#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <limits>

struct Gopher{
  long double x,y,v;
  Gopher(long double xIn, long double yIn, long double vIn) : x(xIn), y(yIn), v(vIn){}
  long double dist(long double xIn, long double yIn){
    return std::sqrt(std::pow(x-xIn,2) + std::pow(y-yIn,2));
  }
};

struct Hole{
  long double x,y;
  Hole(long double xIn, long double yIn) : x(xIn), y(yIn) {}
};

struct Edge{
  long gopher, hole, index, flow;
  long double dist;

  Edge(long gIn, long hIn, long iIn, long double dIn, long fIn = 0) :
    gopher(gIn), hole(hIn), index(iIn), flow(fIn), dist(dIn){}

  bool operator > (const Edge &other) const {
    return dist > other.dist;
  }
};

long fordFulkerson(std::vector<std::vector<Edge>> graph){

  long maxFlow = 0;

  while(true){
    Edge edge(0, 0, -1, 0);
    for(long i = 0; i < (long) graph.size(); i++){
      for (Edge e : graph[i]){
        if (e.flow == 0){
          edge = e;;
          break;
        }
      }
      if (!(edge.index < 0)){break;}
    }
    if (edge.index < 0){break;}

    maxFlow += 1;
    graph[edge.gopher][edge.index].flow += 1;
  }
  return maxFlow;
}


int main(void){
  long double N, M, S, V;
  std::cin >> N >> M >> S >> V;

  std::vector<Gopher> gophers;
  std::vector<Hole> holes;
  std::vector<std::vector<Edge>> graph(N);

  for (long i = 0; i < N; i++){
    long double x,y;
    std::cin >> x >> y;
    gophers.emplace_back(x,y,V);
  }

  for (long i = 0; i < M; i++){
    long double x,y;
    std::cin >> x >> y;
    holes.emplace_back(x,y);
    // Really >= ?
    for (long j = 0; j < N; j++){
      if (S*V >= gophers[j].dist(x,y) ){
        graph[j].emplace_back(j, i, graph[j].size(),gophers[j].dist(x,y));
      }
    }
  }

  long result = fordFulkerson(graph);
  std::cout << N - result << '\n';

  return 0;
}

/*Let A be the set of gophers and B be the set of holes. There is an
edge from gopher a ∈ A to hole b ∈ B if the distance between them is
at most s*v, i.e. the maximum distance a gopher can run in the
available time.

A solution consists of a maximum-size subset of the edges in this
graph, such that (1) each a ∈ A has at most one edge, (2) each b ∈ B
has at most one edge. The constraints represent the rules that each
gopher can only go to one hole, and each hole can only fit one
gopher. The number of "vulnerable" gophers is then the number of
gophers minus the number of edges in the matching.

The graph takes O(mn) time to construct, and a maximum cardinality
matching can be found in O(mn) time or less using a standard algorithm
such as Ford–Fulkerson, where m is the number of gophers and n is the
number of holes.

If that isn't efficient enough for the online judge, you can use a
more efficient algorithm to find the matching, and a more efficient
way to find the edges in the graph, e.g. using a quadtree to query
which holes are within distance s*v of a gopher in under O(n) time.
*/
