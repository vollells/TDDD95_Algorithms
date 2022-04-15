/*
 * Author: Victor Lells (vicle728)
 * Problem: Edmondskarp mincut.
 * Time Complexity: Look at individual functions.
 */

#include <vector>

struct Edge{
  long sNode, eNode, index;
  long long cap, flow;
  Edge* reverse;
  Edge(long sIn, long eIn, long long cIn, long iIn, Edge* pIn = nullptr) : sNode(sIn), eNode(eIn),
                                                                           index(iIn), cap(cIn),
                                                                           flow(0), reverse(pIn){}
  ~Edge(){};
  bool operator == (const Edge &other) const {
    return sNode == other.sNode && eNode == other.eNode;
  }
};

struct Graph{
  long N;
  long long F;
  std::vector<std::vector<Edge*>> edges;

  Graph(long inN) : N(inN), F(0), edges(std::vector<std::vector<Edge*>>(N)){}
  ~Graph(){
    for(long i = 0; i < (long) edges.size(); i++){
      for(long j = 0; j < (long) edges[i].size(); j++){
        delete edges[i][j];
      }
    }
  }
  /*
   * Fuction: addEdge
   * TC: Constant
   */
  void addEdge(long u, long v, long long c){
    Edge* f = new Edge(u, v, c, edges[u].size());
    Edge* r = new Edge(v, u, 0, edges[v].size(), f);
    f->reverse = r;
    edges[u].push_back(f);
    edges[v].push_back(r);
  }
};

/*
 * Function: bfs
 *
 * Algo: Generic BFS, we go through all the edges of vertex and then
 * add that vertex to the queue if it has not been explored before.
 *
 * Input :
 * - graph: The current graph.
 * - sourceIndex: Index for source vertex.
 *
 * Output:
 * - result: Graph with max flow assigned to all edges
 *
 * TC: O(|V| + |E|) - Since we always go through all the edges of a
 * node and try to reach each node once.
 */
std::vector<Edge&> bfs (Graph&, long, long);


/*
 * Function: edmondsKarpMinCut
 *
 * Algo: Try to find a path from the source to the sink with more
 * available flow, if yes we fill the path (def. by min edges
 * available flow.). If no, we have found the maxflow assignment
 * possible, return minCut aka the none found path.
 *
 * Input :
 * - graph: The current graph.
 * - sourceIndex: Index for source vertex.
 * - sinkIndex: Index for sink vertex.
 *
 * Output:
 * - minCut: Vector with minCut where != nullptr
 *
 * TC: O((|V|+|E|) * |V| * |E|) where V vertices, E edges, and worst case
 * time complexity. Since the most time consuming part of the loop is
 * finding the path which is ((|V|+|E|) with bfs) and we need to
 * saturate, in worst case, E edges, and each path has the length of
 * atmost |V|.
 */
std::vector<Edge*> edmondsKarpMinCut (Graph&, long);

/*
 * Function: main
 *
 * Use: Handles the data input and answer output.
 *
 * TC: N/A - kattis input/output parser.
 */
int main(void);
