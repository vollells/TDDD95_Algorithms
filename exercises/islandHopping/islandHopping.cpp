#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include "disjointSet.h"

template <typename T>
struct Node{
  T hor;
  T ver;
  Node(T horIn, T verIn) : hor(horIn), ver(verIn){}
};

struct Edge{
  long v;
  long u;
  long double dist;
  Edge(long uIn, long vIn, long double distIn) : v(vIn), u(uIn), dist(distIn){}
};

bool operator>(const Edge& lhs, const Edge& rhs) {
    return lhs.dist > rhs.dist;
}

std::vector<Edge> kruskals(std::vector<Node<long double>> &graph,
                           std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge>> &edges){
  std::vector<Edge> result;
  DisjointSet sets = DisjointSet(graph.size());

  while(!edges.empty()){
    Edge e = edges.top();
    edges.pop();
    if (sets.setFind(e.v) != sets.setFind(e.u)){
      result.push_back(e);
      sets.setUnion(e.v, e.u);
    }
  }
  return result;
}

int main(void){
  long N;
  std::cin >> N;
  for(long i = 0; i < N; i++){
    long M;
    std::cin >> M;

    std::vector<Node<long double>> graph;
    std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge>> edges;

    for(long i = 0; i < M; i++){
      long double hor, ver;
      std::cin >> hor >> ver;
      graph.emplace_back(hor, ver);
    }

    for (long i = 0; i < M; i++){
      for (long j = i+1; j < M; j++){
        if (i != j){
          double long dist = std::sqrt(std::pow(graph[i].hor-graph[j].hor,2) +
                                     std::pow(graph[i].ver-graph[j].ver,2));
          edges.emplace(i, j, dist);
        }
      }
    }


    std::vector<Edge> result = kruskals(graph, edges);
    long double maxDist = 0;
    for (Edge e: result){
      maxDist += e.dist;
    }
    std::cout << maxDist << '\n';
  }

  return 0;
}

// while(!edges.empty()){
//   Edge e = edges.top();
//   edges.pop();
//   std::cout << "u: " << e.u << " v: " << e.v << " dist: " << e.dist << '\n';
//  }
