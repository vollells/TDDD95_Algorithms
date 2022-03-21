/*
 * Author: Victor Lells (vicle728)
 * Problem: Find eulerian cycle.
 * Time Complexity: Look at individual functions.
 * Use: Include the eulerianPath header file
 */

#include <vector>

template<typename T>
struct Edge{
  T startNode, endNode;
  Edge(T uIn, T vIn) : startNode(uIn), endNode(vIn){}
};

template<typename T>
struct Graph{
  T N;
  std::vector<std::vector<Edge<T>>> inEdges, outEdges;

  Graph(T inN) : N(inN){
    inEdges = std::vector<std::vector<Edge<T>>>(N);
    outEdges = std::vector<std::vector<Edge<T>>>(N);
  }
  /*
   * Fuction: addEdge
   *
   * TC: Constant
   */
  void addEdge(T u, T v){
    outEdges[u].emplace_back(u,v);
    inEdges[v].emplace_back(u,v);
  }
};


/*
 * Function: eulerianPath
 *
 * Algorithm (source: http://www.graph-magics.com/articles/euler.php):
 * We start with an empty stack and an empty eulerian path/cycle
 * (result). We then choose a start node. If all vertices have same
 * out-degrees as in-degrees choose node 0 as start (eulerian
 * Cycle). But iff two vertices have out-degree + 1 and in-degree + 1
 * respectively choose the with one greater out-degree than its
 * in-degree as start (eulerian path).Otherwise we know no euler
 * circuit or path exists.
 *   If current vertex has no out-going edges add it to result and
 * remove the last vertex from the stack and set it as the current
 * one. Otherwise add the vertex to the stack, take any of its
 * out-going edges, remove the edge between that vertex and selected
 * neighbor, and set that neighbor as the current vertex.  Repeat
 * until the current vertex has no more out-going edges and the stack
 * is empty.
 *   Then check if all outgoing edges are removed, if no we
 * have a disconnected graph.
 *
 * Input :
 * - graph: The current graph.
 *
 * Output:
 * - result: vector with all visisted nodes in reverse order.
 *
 * TC: O(|Nodes| * |Edges|)
 */
std::vector<long> eulerianPath(Graph<long> graph);

/*
 * Function: main
 *
 * Use: Handles the data input and answer output.
 *
 * TC: N/A - kattis input/output parser.
 */
int main(void);
