/*
 * Author: Victor Lells (vicle728)
 * Problem: Djikstras Shortest Path.
 * Time Complexity: Look at individual functions.
 * Use: Include the shortestpath2 header file
 */

#include <limits>
#include <vector>
#include <cmath>

template<typename T>
struct Node{
  T node, cost;
  Node(T nIn, T cIn) : node(nIn), cost(cIn){}
  bool operator > (const Node &other) const {
    return cost > other.cost;
  }
};

template<typename T>
struct Edge{
  T endNode, cost, t0, p;
  Edge(T nIn, T cIn, T t0In, T tIn) : endNode(nIn), cost(cIn),
                                      t0(t0In), p(tIn){}
  /*
   * Fuction: nextP
   *
   * TC: Constant
   */
  T nextP(T t){
    if (t <= t0){
      return t0;
    }
    if (p != 0) {
      return (std::ceil((t-t0) / (double)p) * p) + t0;
    }
    return std::numeric_limits<T>::max();
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
  void addEdge(T u, T v, T t0, T t, T c){
    edges[u].emplace_back(v, c, t0, t);
  }
};


/*
 * Function: shortestPath
 *
 * Use: Uses a prio queue which always orders the edges according to
 * minimum distance, this is compared to the best distance/path in the
 * result vector. The cost of getting to neighbors is calculated from
 * the next available time/cost slot and not the current time/cost.
 *
 * Input :
 * - graph: The current graph.
 * - startNode: Start index for the search.
 *
 * Output:
 * - result: vector with distance and previous node information per node.
 *
 * TC: O((|M|+|N|) * log(|N|)) where N nodes, M edges, and worst case
 * time complexity.
 */
std::vector<Node<long>> shortestPath (Graph<long>&, long);

/*
 * Function: main
 *
 * Use: Handles the data input and answer output.
 *
 * TC: N/A - kattis input/output parser.
 */
int main(void);
