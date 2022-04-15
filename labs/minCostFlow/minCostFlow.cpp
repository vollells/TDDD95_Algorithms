/*
 * Author: Victor Lells (vicle728)
 * Problem: fordfulkerson mincost maxflow.
 * Comments: Check minCostFlow.h
 * Use: Include the minCostFlow.h header file
 */

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>
#include "minCostFlow.h"

std::vector<Edge*> djikstra(Graph &graph, long start){
  std::vector<Edge*> result (graph.N, nullptr);
  std::vector<long> distances (graph.N, INT32_MAX);
  std::priority_queue<Edge> queue;

  distances[start] = 0;
  queue.push(Edge(-1, start, 0, 0, 0));

  while (!queue.empty()){
    Edge u = queue.top();
    queue.pop();

    for(Edge* e : graph.edges[u.eNode]){
      long altCost = e->cost + distances[e->sNode];
      if (e->eNode != start && e->cap > e->flow && altCost < distances[e->eNode]){
        distances[e->eNode] = altCost;
        result[e->eNode] = e;
        queue.push(Edge(e->sNode, e->eNode, altCost, 0, 0));
      }
    }
  }
  return result;
}

void fordFulkerson(Graph &graph, long source, long sink){

  while (true){
    std::vector<Edge*> foundPath = djikstra(graph, source);
    if (foundPath[sink] == nullptr){break;}

    long long pathFlow = LLONG_MAX;
    for(Edge* e = foundPath[sink]; e != nullptr; e = foundPath[e->sNode]){
      pathFlow = std::min(pathFlow,  e->cap - e->flow);
    }

    graph.F += pathFlow;

    for(Edge* e = foundPath[sink]; e != nullptr; e = foundPath[e->sNode]){
      e->flow += pathFlow;
      e->reverse->flow -= pathFlow;
    }
  }
}

int main(void){
  long N, M, S, T;
  std::cin >> N >> M >> S >> T;

  Graph graph = Graph(N);
  for(long i = 0; i < M; i++){
    long U, V, W;
    long long C;
    std::cin >> U >> V >> C >> W;
    graph.addEdge(U, V, C, W);
  }

  fordFulkerson(graph, S, T);

  for(std::vector<Edge*> v : graph.edges){
    for(Edge* e : v){
      if(e->cost > 0 && e->flow > 0){
        graph.C += e->cost * e->flow;
      }
    }
  }

  std::cout << graph.F << ' ' << graph.C << '\n';

  return 0;
}
