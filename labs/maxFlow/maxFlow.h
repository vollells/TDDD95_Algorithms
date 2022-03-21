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
  std::vector<std::vector<Edge>> edges;

  Graph(long inN) : N(inN), F(0), edges(std::vector<std::vector<Edge>>(N)){}
  ~Graph(){
    for(long i = 0; i < (long) edges.size(); i++){
      for(long j = 0; j < (long) edges[i].size(); j++){
        delete edges[i][j].reverse;
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
    edges[u].push_back(*f);
    edges[v].push_back(*r);
  }

  /*
   * Fuction: updateEdge
   * TC: O(|M|)
   */
  void updateEdge(long u, long v, long long f){
    for(long i = 0; i < (long) edges[u].size(); i++){
      if(edges[u][i].eNode == v){
        edges[u][i].flow += f;
        edges[u][i].reverse->flow -= f;
        break;
      }
    }
  }

  /*
   * Fuction: usedEdges;
   * TC: O(|M|) Nr Edges in graph;
   */
  long usedEdges(){
    long counter = 0;
    for(std::vector<Edge> v : edges){
      for(Edge e : v){
        if(e.flow > 0){
          counter++;
        }
      }
    }
    return counter;
  }
};

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
std::vector<Edge&> bfs (Graph&, long, long);


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
void edmondsKarp (Graph&, long);

/*
 * Function: main
 *
 * Use: Handles the data input and answer output.
 *
 * TC: N/A - kattis input/output parser.
 */
int main(void);
