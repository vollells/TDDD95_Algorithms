#include <iostream>
#include <vector>
#include <cmath>

struct Edge{
  long u, v;
  Edge(long uIn, long vIn) : u(uIn), v(vIn){}
};

std::vector<bool> kruskals(long nodes, std::vector<std::vector<Edge>> &edges){

  std::vector<Edge> neighbours;
  neighbours.emplace_back(1,1);
  std::vector<bool> result(nodes);

  while(!neighbours.empty()){
    Edge e = neighbours.back();
    neighbours.pop_back();
    if (!result[e.v]){
      result[e.v] = true;
      for (Edge neigh : edges[e.v]){
        neighbours.push_back(neigh);
      }
    }
  }
  return result;
}

int main(void){

  long N, M;
  std::cin >> N >> M;
  std::vector<std::vector<Edge>> edges(N+1);

  for(long i = 0; i < M; i++){
    long  U, V;
    std::cin >> U >> V;
    edges[U].emplace_back(U, V);
    edges[V].emplace_back(V, U);
  }

  std::vector<bool> result = kruskals(N+1, edges);

  bool pConn = true;
  for (int i = 1; i < N+1; i++){
    if (!result[i]){
      std::cout << i << '\n';
    }
    pConn = pConn && result[i];
  }

  if (pConn) {
    std::cout << "Connected" << '\n';
  }

  return 0;
}
