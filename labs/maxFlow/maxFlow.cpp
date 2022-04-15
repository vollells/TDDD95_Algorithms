/*
 * Author: Victor Lells (vicle728)
 * Problem: Edmondskarp maxflow.
 * Comments: Check maxFlow.h
 * Use: Include the maxFlow.h header file
 */


#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <climits>
#include <cmath>
#include "maxFlow.h"

std::vector<Edge*> bfs(Graph &graph, long start){
  std::vector<Edge*> result (graph.N, nullptr);
  std::queue<long> queue;
  queue.push(start);

  while (!queue.empty()){
    long u = queue.front();
    queue.pop();

    for(Edge* e : graph.edges[u]){
      if (result[e->eNode] == nullptr && e->eNode != start && e->cap > e->flow){
        result[e->eNode] = e;
        queue.push(e->eNode);
      }
    }
  }
  return result;
}

void edmondsKarp(Graph &graph, long source, long sink){

  while (true){
    std::vector<Edge*> foundPath = bfs(graph, source);
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
    long U, V;
    long long C;
    std::cin >> U >> V >> C;
    graph.addEdge(U, V, C);
  }

  edmondsKarp(graph, S, T);

  std::cout << graph.N << ' ' << graph.F << ' ' << graph.usedEdges() << '\n';
  for(std::vector<Edge*> v : graph.edges){
    for(Edge* e : v){
      if(e->flow > 0){
        std::cout << e->sNode << ' ' << e->eNode << ' ' << e->flow << '\n';
      }
    }
  }

  return 0;
}
