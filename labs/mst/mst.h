/*
 * Author: Victor Lells (vicle728)
 * Problem: Kruskal's Minimum Spanning Tree.
 * Time Complexity: Look at individual functions.
 * Use: Include the mst header file and disjointSet header/cpp files.
 */

#include <vector>
#include <queue>

struct Edge{
  long u, v, cost;
  Edge(long uIn, long vIn, long cIn) : u(uIn), v(vIn), cost(cIn){}
  bool operator > (const Edge& other) const {
    return cost > other.cost;
  }
};

/*
 * Function: kruskals
 *
 * Use: It is a greedy algorithm which at each step adds the next
 * lowest-weight edge that will not form a cycle to the minimum
 * spanning forest. Checking for a cycle is done by adding all nodes
 * into a disjointSet.
 *
 * Input :
 * - edges: All the edges in the graph orderd by the cost.
 * - nodes: Ammount of nodes.
 * Output:
 * - result: vector with distance and previous node information per node.
 *
 * TC: O(|M|* log(|N|)) where N nodes, M edges, and worst case time
 * complexity. Since we go through all edges to check for the cheapest
 * path to a node we haven't found yet. This we check in the disjoint
 * set which takes O(log(|N|)) (Since it's not fully optimized,
 * otherwise could be constant).
 */
std::vector<Edge> kruskals(long, std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge>>&);


/*
 * Function: outputSort
 * Use: Sorting criteria for achieving a lexical order.
 *
 * Input :
 * - lhs: lhs edge
 * - rhs: rhs edge
 * Output:
 * - result: bool
 *
 * TC: constant
 */
bool outputSort (Edge&, Edge&);

/*
 * Function: main
 * Use: Handles the data input and answer output.
 *
 * TC: N/A - kattis input/output parser.
 */
int main(void);
