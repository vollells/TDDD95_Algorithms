#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <climits>
#include <cmath>
#include "maxFlow.h"

std::vector<Edge> bfs(Graph &graph, long start){
  std::vector<Edge> result (graph.N, Edge(-1, -1, 0, 0));
  std::queue<long> queue;
  queue.push(start);

  while (!queue.empty()){
    long u = queue.front();
    queue.pop();

    for(Edge e : graph.edges[u]){
      if (result[e.eNode].eNode == -1 && e.eNode != start && e.cap > e.flow){
        result[e.eNode] = e;
        queue.push(e.eNode);
      }
    }
  }
  return result;
}

void edmondsKarp(Graph &graph, long source, long sink){

  while (true){
    std::vector<Edge> foundPath = bfs(graph, source);
    if (foundPath[sink].eNode == -1){break;}

    long long pathFlow = LLONG_MAX;
    for(Edge e = foundPath[sink]; e.sNode != -1; e = foundPath[e.sNode]){
      pathFlow = std::min(pathFlow,  e.cap - e.flow);
    }

    graph.F += pathFlow;

    for(Edge e = foundPath[sink]; e.sNode != -1; e = foundPath[e.sNode]){
      graph.edges[e.sNode][e.index].flow += pathFlow;
      graph.edges[e.sNode][e.index].reverse->flow += pathFlow;
      // graph.updateEdge(e.sNode, e.eNode, pathFlow);
    }
  }
}

int main(void){
  long N, M, S, T;
  std::cin >> N >> M >> S >> T;

  Graph *graph = new Graph(N);
  for(long i = 0; i < M; i++){
    long U, V;
    long long C;
    std::cin >> U >> V >> C;
    graph->addEdge(U, V, C);
  }

  edmondsKarp(*graph, S, T);

  std::cout << graph->N << ' ' << graph->F << ' ' << graph->usedEdges() << '\n';
  for(std::vector<Edge> v : graph->edges){
    for(Edge e : v){
      if(e.flow > 0){
        std::cout << e.sNode << ' ' << e.eNode << ' ' << e.flow << '\n';
      }
    }
  }

  delete graph;
  return 0;
}
