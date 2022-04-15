/*
 * Author: Victor Lells (vicle728)
 * Problem: Kruskal's Minimum Spanning Tree.
 * Use: Include the mst header file
 * Comments: In the header file.
 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include "disjointSet.h"
#include "mst.h"

std::vector<Edge> kruskals(long nodes, std::vector<Edge> &edges){

  if(nodes == 1){
    return {};
  }
  std::vector<Edge> result;
  DisjointSet sets = DisjointSet(nodes);

  while(!edges.empty()){
    Edge e = edges.back();
    edges.pop_back();
    if (sets.setFind(e.v) != sets.setFind(e.u)){
      result.push_back(e);
      sets.setUnion(e.v, e.u);
      sets.setUnion(e.u, e.v);
    }
  }
  return result;
}


bool outputSort (Edge& lhs, Edge& rhs){
  if(lhs.u == rhs.u){
    return lhs.v < rhs.v;
  }
  return lhs.u < rhs.u ;
}

int main(void){

  while (true) {
    long N, M;
    std::cin >> N >> M;
    if(N + M == 0){break;}

    std::vector<Edge> edges;

    for(long i = 0; i < M; i++){
      long  U, V, W;
      std::cin >> U >> V >> W;
      edges.emplace_back(std::min(U, V), std::max(U, V), W);
    }
    std::sort(edges.begin(), edges.end(), std::greater<Edge>());
    std::vector<Edge> &&result = kruskals(N, edges);
    if ((long) result.size() != N-1) {
      std::cout << "Impossible" << '\n';
      continue;
    }

    long totalCost = 0;
    for (Edge e: result){
      totalCost += e.cost;
    }
    std::cout << totalCost << '\n';

    std::sort(result.begin(), result.end(), outputSort);
    for (Edge e: result){
      std::cout << e.u << " " << e.v << '\n';
    }
  }

  return 0;
}

