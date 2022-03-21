#include <iostream>
#include <vector>
#include <queue>
#include <utility>

template<typename T>
struct Edge{
  T endNode, gas, cost;
  Edge(T nIn, T gIn,  long cIn) : endNode(nIn), gas(gIn), cost(cIn){}
  bool operator > (const Edge &other) const {
    return cost > other.cost;
  }
};

template<typename T>
struct Graph{
  T N;
  std::vector<std::vector<Edge<T>>> edges;
  std::vector<std::vector<T>> gasCost;
  std::vector<T> price;
  Graph(T inN) : N(inN){
    edges = std::vector<std::vector<Edge<T>>>(N);
    gasCost = std::vector<std::vector<T>>(N, std::vector<T>(101, INT32_MAX));
    price = std::vector<T>(N);
  }
  void graphReset(){
    gasCost = std::vector<std::vector<T>>(N, std::vector<T>(101, INT32_MAX));
  }
};


std::vector<Edge<long>> shortestPath (Graph<long> &graph, long startIndex, long cap){

  std::vector<Edge<long>> result(graph.edges.size(), Edge<long>{-1, 0, INT32_MAX});
  // Using edges as Nodes
  std::priority_queue<Edge<long>, std::vector<Edge<long>>, std::greater<Edge<long>>> unsetNodes;

  unsetNodes.emplace(startIndex, 0, 0);
  graph.gasCost[startIndex][0] = 0;
  result[startIndex] = Edge<long>(startIndex, 0, 0);

  while(!unsetNodes.empty()){
    Edge<long> curr = unsetNodes.top();
    unsetNodes.pop();

    //EndNode is actually current Node
    // if (graph.gasCost[curr.endNode][curr.gas] < curr.cost){continue;}

    if(curr.gas < cap && curr.cost + graph.price[curr.endNode] < graph.gasCost[curr.endNode][curr.gas+1]){
      graph.gasCost[curr.endNode][curr.gas+1] = curr.cost + graph.price[curr.endNode];
      unsetNodes.emplace(curr.endNode, curr.gas+1, curr.cost + graph.price[curr.endNode]);
    }

    for(long i = 0; (unsigned long) i < graph.edges[curr.endNode].size(); i++){
      long altIndex = graph.edges[curr.endNode][i].endNode;
      long altCost = graph.edges[curr.endNode][i].cost;

      if (curr.gas >= altCost){
        long newGas = curr.gas - altCost;
        if (curr.cost < graph.gasCost[altIndex][newGas]){
          graph.gasCost[altIndex][newGas] = curr.cost;
          unsetNodes.emplace(altIndex, newGas, curr.cost);
          if(curr.cost < result[altIndex].cost){
            result[altIndex] = Edge<long>(curr.endNode, newGas, curr.cost);
          }
        }
      }
    }
  }

  return result;
}


int main(void){

  long M, N;
  std::cin >> N >> M;

  Graph<long> graph(N);

  for (long i=0; i<N; i++){
    std::cin >> graph.price[i];
  }
  for (long i=0; i<M; i++){
    long U, V, D;
    std::cin >> U >> V >> D;
    graph.edges[U].emplace_back(V, 0, D);
    graph.edges[V].emplace_back(U, 0, D);
  }

  long Q;
  std::cin >> Q;
  for(long i=0; i<Q; i++){
    long C, S, E;
    std::cin >> C >> S >> E;
    std::vector<Edge<long>> result;
    graph.graphReset();
    result = shortestPath(graph, S, C);

    if (result[E].cost < INT32_MAX){
      std::cout << result[E].cost << '\n';
    } else {
      std::cout << "impossible" << '\n';
    }
  }
}
