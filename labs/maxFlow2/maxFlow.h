#include <vector>

/*
 * Function: bfs
 *
 *
 * Input :
 * - graph: The current graph.
 * - sourceIndex: Index for source vertex.
 * - sinkIndex: Index for sink vertex.
 *
 * Output:
 * - result: Graph with max flow assigned to all edges
 *
 * TC: O(|V| + |E|)
 */
std::vector<long> bfs (std::vector<std::vector<long long>>&, long, long);


/*
 * Function: edmondsKarp
 *
 *
 * Input :
 * - graph: The current graph.
 * - sourceIndex: Index for source vertex.
 * - sinkIndex: Index for sink vertex.
 *
 * Output:
 * - result: Graph with max flow assigned to all edges
 *
 * TC: O((|M|+|N|) * log(|N|)) where N nodes, M edges, and worst case
 * time complexity.
 */
long long edmondsKarp (std::vector<std::vector<long long>>&, long, long);

/*
 * Function: main
 *
 * Use: Handles the data input and answer output.
 *
 * TC: N/A - kattis input/output parser.
 */
int main(void);
