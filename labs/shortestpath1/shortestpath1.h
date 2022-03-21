/*
 * Author: Victor Lells (vicle728)
 * Problem: Djikstras Shortest Path.
 * Time Complexity: Look at individual functions.
 * Use: Include the shortestpath1 header file
 */

#include <vector>

template<typename T>
struct Edge{
  T endNode, cost;
  Edge(T nIn, long cIn) : endNode(nIn), cost(cIn){}
  bool operator > (const Edge &other) const {
    return cost > other.cost;
  }
};

template<typename T>
struct Graph{
  T N;
  std::vector<std::vector<Edge<T>>> edges;

  Graph(T inN) : N(inN){
    edges = std::vector<std::vector<Edge<T>>>(N);
  }
  /*
   * Fuction: addEdge
   *
   * TC: Constant
   */
  void addEdge(T u, T v, T c){
    edges[u].emplace_back(v, c);
  }
};


/*
 * Function: shortestPath
 *
 * Use: Uses a prio queue which always orders the edges according to minimum distance, this
 * is compared to the best distance/path in the result vector.
 *
 * Input :
 * - Graph: The current graph.
 * - startNode: Start index for the search.
 *
 * Output:
 * - Result vector with distance and previous node information per node.
 *
 * TC: O((|M| + |N|) * log(|N|)) where N nodes, M edges, and worst case
 * time complexity.
 */
std::vector<Edge<long>> shortestPath (Graph<long>&, long);

/*
 * Function: main
 *
 * Use: Handles the data input and answer output.
 *
 * TC: N/A - kattis input/output parser.
 */
int main(void);
