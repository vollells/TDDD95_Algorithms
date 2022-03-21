/*
 * Author: Victor Lells (vicle728)
 * Problem: Djikstras Shortest Path.
 * Use: Include the shortestpath2 header file
 * Comments: In the header file.
 */

#include <vector>
#include <queue>
#include <limits>
#include <iostream>
#include "shortestpath2.h"

std::vector<Node<long>> shortestPath(Graph<long> &graph, long startNode){

  long MAX = std::numeric_limits<long>::max();
  std::vector<Node<long>> result(graph.N, Node<long>(-1, MAX));
  std::priority_queue<Node<long>, std::vector<Node<long>>, std::greater<Node<long>>> unsetNodes;

  unsetNodes.emplace(startNode, 0);
  result[startNode] = Node<long>(startNode, 0);

  while(!unsetNodes.empty()){
    Node<long> curr = unsetNodes.top();
    unsetNodes.pop();

    long currIndex = curr.node;

    for(long i = 0; i < (long) graph.edges[currIndex].size(); i++){
      long altIndex = graph.edges[currIndex][i].endNode;
      long nextTime = graph.edges[currIndex][i].nextP(result[currIndex].cost);
      long altCost = nextTime + graph.edges[currIndex][i].cost;

      if (nextTime != MAX && result[altIndex].cost > altCost){
        result[altIndex] = Node<long>(currIndex, altCost);
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
      long U, V, T0, P, D;
      std::cin >> U >> V >> T0 >> P >> D;
      graph.addEdge(U, V, T0, P, D);
    }

    // {{Dist, Prev}, {Dist, Prev}, ...}
    std::vector<Node<long>> result = shortestPath(graph, S);

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
