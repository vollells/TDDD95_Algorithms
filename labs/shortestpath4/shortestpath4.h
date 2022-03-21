/*
 * Author: Victor Lells (vicle728)
 * Problem: Floyd–Warshall Shortest Path.
 * Time Complexity: Look at individual functions.
 * Use: Include the shortestpath4 header file
 */

#include <vector>

template<typename T>
struct Edge{
  T startNode, endNode, cost;
  Edge(T uIn, T vIn, T cIn) : startNode(uIn), endNode(vIn), cost(cIn){}
};

template<typename T>
struct Graph{
  T N;
  std::vector<Edge<T>> edges;

  Graph(T inN) : N(inN){
    edges = std::vector<Edge<T>>();
  }
  /*
   * Fuction: addEdge
   *
   * TC: Constant
   */
  void addEdge(T u, T v, T c){
    edges.emplace_back(u, v, c);
  }
};

/*
 * Function: shortestPath
 *
 * Use: Goes through all nodes and tries to find the shortest path to
 * all other nodes, it does this by checking if the current path is
 * shortest or a path through a node k is shorter (It checks all
 * k). If a node is in a neg cycle can be checked to see if the cost
 * to go from from a node k to itself is negative; and if we kan
 * create a path from i -> k -> j then that cost is also -inf as it
 * can reach the negative cycle.
 *
 * Input :
 * - graph: The current graph.
 *
 * Output:
 * - result: vector vector with distance for all paths between nodes
 *
 * TC: O(|Nodes|^3)
 */
std::vector<std::vector<long>> shortestPath (Graph<long>&);

/*
 * Function: main
 *
 * Use: Handles the data input and answer output.
 *
 * TC: N/A - kattis input/output parser.
 */
int main(void);
