/*
 * Author: Victor Lells (vicle728)
 * Problem: Djikstras Shortest Path.
 * Use: Include the shortestpath1 header file
 * Comments: In the header file.
 */

#include <vector>
#include <set>
#include <utility>
#include <iostream>
#include "shortestpath1.h"

std::vector<std::pair<long,long>> shortestPath (Graph graph, long start_index){

  std::vector<std::pair<long,long>> result(graph.N, {INT32_MAX, -1});
  std::set<std::pair<long, long> > unsetNodes;

  unsetNodes.insert(std::make_pair(0, start_index));
  result[start_index].first = 0;
  result[start_index].second = start_index;

  while(!unsetNodes.empty()){
    std::pair<long, long> curr = *(unsetNodes.begin());
    unsetNodes.erase(unsetNodes.begin());

    int currIndex = curr.second;

    for(long i = 0; (unsigned long) i < graph.edges->at(currIndex).size(); i++){
      long altIndex = graph.edges->at(currIndex)[i].endNode;
      long altCost = graph.edges->at(currIndex)[i].cost;

      if (result[altIndex].first > result[currIndex].first + altCost){

        if (result[altIndex].first != INT32_MAX){
          unsetNodes.erase(unsetNodes.find(std::make_pair(result[altIndex].first, altIndex)));
        }

        result[altIndex].first = result[currIndex].first + altCost;
        result[altIndex].second = currIndex;
        unsetNodes.insert(std::make_pair(result[altIndex].first, altIndex));
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

    Graph graph (N);
    for(long i = 0; i < M; i++){
      long U, V, W;
      std::cin >> U >> V >> W;
      graph.addEdge(U, V, W);
    }

    // {{Dist, Prev}, {Dist, Prev}, ...}
    std::vector<std::pair<long,long>> result;
    result = shortestPath(graph, S);

    for(long i = 0; i < Q; i++){
      long nodeQ;
      std::cin >> nodeQ;
      if(result[nodeQ].first != INT32_MAX){
        std::cout << result[nodeQ].first << '\n';
      } else {
        std::cout << "Impossible" << '\n';
      }

    }
  }

  return 0;
}
