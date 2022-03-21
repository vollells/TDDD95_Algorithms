/*
 * Author: Victor Lells (vicle728)
 * Problem: Djikstras Shortest Path.
 * Use: Include the shortestpath1 header file
 * Comments: In the header file.
 */

#include <vector>
#include <queue>
#include <limits>
#include <iostream>
#include "shortestpath1.h"

std::vector<Edge<long>> shortestPath(Graph<long> &graph, long startNode){

  std::vector<Edge<long>> result(graph.N, Edge<long>(-1, std::numeric_limits<long>::max()));
  std::priority_queue<Edge<long>, std::vector<Edge<long>>, std::greater<Edge<long>>> unsetNodes;

  unsetNodes.emplace(startNode, 0);
  result[startNode] = Edge<long>(startNode, 0);


  while(!unsetNodes.empty()){
    Edge<long> curr = unsetNodes.top();
    unsetNodes.pop();

    long currIndex = curr.endNode;

    for(long i = 0; i < (long)graph.edges[currIndex].size(); i++){
      long altIndex = graph.edges[currIndex][i].endNode;
      long altCost = graph.edges[currIndex][i].cost;

      if (result[altIndex].cost > result[currIndex].cost + altCost){
        result[altIndex] = Edge<long>(currIndex, result[currIndex].cost + altCost);
        unsetNodes.emplace(altIndex, result[altIndex].cost);
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
    std::vector<Edge<long>> result = shortestPath(graph, S);

    for(long i = 0; i < Q; i++){
      long nodeQ;
      std::cin >> nodeQ;
      if(result[nodeQ].cost != std::numeric_limits<long>::max()){
        std::cout << result[nodeQ].cost << '\n';
      } else {
        std::cout << "Impossible" << '\n';
      }

    }
  }

  return 0;
}
