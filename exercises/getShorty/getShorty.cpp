#include <vector>
#include <queue>
#include <limits>
#include <iostream>

template<typename T>
struct Edge{
  long endNode;
  T cost;
  Edge(long nIn, T cIn) : endNode(nIn), cost(cIn){}
  bool operator < (const Edge &other) const {
    return cost < other.cost;
  }
};

template<typename T>
struct Graph{
  long N;
  std::vector<std::vector<Edge<T>>> edges;

  Graph(T inN) : N(inN){
    edges = std::vector<std::vector<Edge<T>>>(N);
  }

  void addEdge(long u, long v, T c){
    edges[u].emplace_back(v, c);
    edges[v].emplace_back(u, c);
  }
};

std::vector<double> shortestPath(Graph<double> &graph, long startNode){

  std::vector<double> result(graph.N, 0);
  std::priority_queue<Edge<double>> unsetNodes;

  unsetNodes.emplace(startNode, 1.0);
  result[startNode] = 1.0;


  while(!unsetNodes.empty()){
    Edge<double> curr = unsetNodes.top();
    unsetNodes.pop();

    long currIndex = curr.endNode;

    for(long i = 0; i < (long)graph.edges[currIndex].size(); i++){
      long altIndex = graph.edges[currIndex][i].endNode;
      double altCost = graph.edges[currIndex][i].cost * curr.cost;

      if (altCost > result[altIndex]){
        result[altIndex] = altCost;
        unsetNodes.emplace(altIndex, result[altIndex]);
      }
    }
  }

  return result;
}


int main(void){

  while(true){
    long N, M;
    std::cin >> N >> M;

    if ((N+M) == 0){break;}

    Graph<double> graph (N);
    for(long i = 0; i < M; i++){
      long U, V;
      double W;
      std::cin >> U >> V >> W;
      graph.addEdge(U, V, W);
    }

    // {{Dist, Prev}, {Dist, Prev}, ...}
    std::vector<double> result = shortestPath(graph, 0);

    printf("%.4f\n", result[N-1]);

  }

  return 0;
}
