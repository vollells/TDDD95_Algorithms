/*
 * Author: Victor Lells (vicle728)
 * Problem: Edmondskarp mincut.
 * Comments: Check mincut.h
 * Use: Include the mincut.h header file
 */


#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <climits>
#include <cmath>
#include "minCut.h"

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

std::vector<Edge*> edmondsKarpMinCut(Graph &graph, long source, long sink){

  std::vector<Edge*> foundPath = {};
  while (true){
    foundPath = bfs(graph, source);
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

  return foundPath;
}

int main(void){
  long N, M, S, T;
  std::cin >> N >> M >> S >> T;

  Graph graph = Graph(N);
  for(long i = 0; i < M; i++){
    long U, V;
    long long C;
    std::cin >> U >> V >> C;
    long index = -1;
    for (int i = 0; i < (long) graph.edges[U].size(); i++){
      if (graph.edges[U][i]->eNode == V){
        index = i;
        break;
      }
    }
    if (index != -1){
      graph.edges[U][index]->cap += C;
    } else {
      graph.addEdge(U, V, C);
    }
  }

  std::vector<Edge*> minCut = edmondsKarpMinCut(graph, S, T);

  long counter = 1;
  for(Edge* e : minCut){
    if(e != nullptr){
      counter++;
    }
  }

  std::cout << counter << '\n';
  for(long i = 0; i < graph.N; i++){
    if(minCut[i] != nullptr || i == S){
        std::cout << i << '\n';
    }
  }

  return 0;
}
