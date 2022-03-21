/*
 * Author: Victor Lells (vicle728)
 * Problem: Bellman-Fords Shortest Path.
 * Use: Include the shortestpath3 header file
 * Comments: In the header file.
 */

#include <vector>
#include <climits>
#include <cmath>
#include <iostream>
#include "shortestpath4.h"

std::vector<std::vector<long>> shortestPath(Graph<long> &graph){

  std::vector<std::vector<long>> result(graph.N, std::vector<long>(graph.N, INT_MAX));

  for(long i = 0; i < graph.N; i++){
    result[i][i] = 0;
  }
  for(Edge<long> e : graph.edges){
    // There can be several edges between nodes, take the lowest cost.
    result[e.startNode][e.endNode] = std::min(e.cost, result[e.startNode][e.endNode]);
  }

  for (long k = 0; k < graph.N; k++){
    for (long i = 0; i < graph.N; i++){
      for (long j = 0; j < graph.N; j++){
        bool goThorughK = result[i][k] != INT_MAX && result[k][j] != INT_MAX;
        if (result[i][j] > result[i][k] + result[k][j] && goThorughK){
          result[i][j] = result[i][k] + result[k][j];
        }
      }
    }
  }

  for (long k = 0; k < graph.N; k++){
    for (long i = 0; i < graph.N; i++){
      for (long j = 0; j < graph.N; j++){
        bool goThorughK = result[i][k] != INT_MAX && result[k][j] != INT_MAX;
        if (result[k][k] < 0 && goThorughK){
          result[i][j] = INT_MIN;
        }
      }
    }
  }

  return result;
}


int main(void){

  while(true){
    long N, M, Q;
    std::cin >> N >> M >> Q;

    if ((N+M+Q) == 0){break;}

    Graph<long> graph (N);
    for(long i = 0; i < M; i++){
      long U, V, W;
      std::cin >> U >> V >> W;
      graph.addEdge(U, V, W);
    }

    // {{Dist, Prev}, {Dist, Prev}, ...}
     std::vector<std::vector<long>>result = shortestPath(graph);

    for(long i = 0; i < Q; i++){
      long nodeU, nodeV;
      std::cin >> nodeU >> nodeV;
      if (result[nodeU][nodeV] == INT_MIN){
        std::cout << "-Infinity" << '\n';
      }
      else if(result[nodeU][nodeV] == INT_MAX){
        std::cout << "Impossible" << '\n';
      } else {
        std::cout << result[nodeU][nodeV] << '\n';
      }
    }
    std::cout << '\n';
  }

  return 0;
}
