/*
 * Author: Victor Lells (vicle728)
 * Problem: Bellman-Fords Shortest Path.
 * Time Complexity: Look at individual functions.
 * Use: Include the shortestpath3 header file
 */


#include <limits>
#include <vector>
#include <cmath>

template<typename T>
struct Node{
  T node, cost;
  bool negC;
  Node(T nIn, T cIn, bool negIn = false) : node(nIn), cost(cIn), negC(negIn){}
};

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
 * Use: Goes through all edges once for every node and modifies the
 * cost to reach each node. After we've done this we go through all
 * edges for every node and check if a node or it's predecessor is in a
 * negative cycle.
 *
 * Input :
 * - graph: The current graph.
 * - startNode: Start index for the search.
 *
 * Output:
 * - result: vector with distance and previous node information per node.
 *
 * TC: O(|Nodes| * |Edges|)
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
