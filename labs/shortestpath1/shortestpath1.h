/*
 * Author: Victor Lells (vicle728)
 * Problem: Djikstras Shortest Path.
 * Time Complexity: Look at individual functions.
 * Use: Include the shortestpath1 header file
 */

#include <vector>

struct Edge{
  long endNode;
  long cost;
  Edge(long endNodeIn, long costIn) : endNode(endNodeIn), cost(costIn){}
};

struct Graph{
  long N;
  std::vector<std::vector<Edge>> *edges;

  Graph(long inN) : N(inN) {
    edges = new std::vector<std::vector<Edge>>(inN, std::vector<Edge>());
  };

  void addEdge(long u, long v, long c){
    edges->at(u).emplace_back(v, c);
  }
};


/*
 * Function: shortestPath
 *
 * Use: Uses a set which always orders the according to distance, this
 * is compared to the best distance/path in the result vector. I also
 * make sure that there are no duplicates in the set.
 *
 * Input :
 * - Graph: The current graph.
 * - startNode: Start index for the search.
 *
 * Output:
 * - Result vector with distance and previous node information per node.
 *
 * TC: O(log(Node) * Edges)
 */
std::vector<std::pair<long,long>> shortestPath (Graph, long);

/*
 * Function: main
 *
 * Use: Handles the data input and answer output.
 *
 * TC: N/A - kattis input/output parser.
 */
int main(void);
