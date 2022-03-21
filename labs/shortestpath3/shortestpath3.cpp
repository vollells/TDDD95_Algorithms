/*
 * Author: Victor Lells (vicle728)
 * Problem: Bellman-Fords Shortest Path.
 * Use: Include the shortestpath3 header file
 * Comments: In the header file.
 */

#include <vector>
#include <queue>
#include <limits>
#include <cmath>
#include <iostream>
#include "shortestpath3.h"

std::vector<Node<long>> shortestPath(Graph<long> &graph, long startNode){

  long MAX = std::numeric_limits<long>::max();
  long MIN = std::numeric_limits<long>::min();
  std::vector<Node<long>> result(graph.N, Node<long>(-1, MAX));
  result[startNode] = Node<long>(startNode, 0);

  for (long i = 0; i < graph.N; i++){
    for (Edge<long> e: graph.edges){
      if (result[e.startNode].cost + e.cost < result[e.endNode].cost && result[e.startNode].cost != MAX){
        result[e.endNode] = Node<long>(e.startNode, result[e.startNode].cost + e.cost);
      }
    }
  }

  for (long i = 0; i < graph.N; i++){
    for (Edge<long> e: graph.edges){
      if(result[e.startNode].cost == MAX) continue;
      if (result[e.startNode].negC || result[e.startNode].cost + e.cost < result[e.endNode].cost){
        result[e.endNode].negC = true;
        result[e.endNode].cost = MIN;
      }
    }
  }

  return result;
}


int main(void){

  while(true){
    long N, M, Q, S;
    std::cin >> N >> M >> Q >> S;

    if ((N+M+Q+S) == 0){break;}

    Graph<long> graph (N);
    for(long i = 0; i < M; i++){
      long U, V, W;
      std::cin >> U >> V >> W;
      graph.addEdge(U, V, W);
    }

    // {{Dist, Prev}, {Dist, Prev}, ...}
    std::vector<Node<long>> result;
    result = shortestPath(graph, S);

    for(long i = 0; i < Q; i++){
      long nodeQ;
      std::cin >> nodeQ;
      if (result[nodeQ].negC){
        std::cout << "-Infinity" << '\n';
      }
      else if(result[nodeQ].cost != std::numeric_limits<long>::max()){
        std::cout << result[nodeQ].cost << '\n';
      } else {
        std::cout << "Impossible" << '\n';
      }

    }
  }

  return 0;
}
