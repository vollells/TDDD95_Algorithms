#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>
#include "maxFlow.h"

bool bfs(std::vector<std::vector<long long>> &graph, long start, long end, std::vector<long>& result){
  std::vector<bool> visited(graph.size(), false);
  std::queue<long> queue;
  queue.push(start);
  visited[start] = true;
  result[start] = -1;

  while (!queue.empty()){
    long u = queue.front();
    queue.pop();

    for(int v = 0; v < (long) graph.size(); v++){
      if(!visited[v] && graph[u][v] > 0){
        result[v] = u;
        visited[v] = true;
        queue.push(v);
        if (v == end){
          return true;
        }
      }
    }
  }
  return false;
}

long long edmondsKarp(std::vector<std::vector<long long>> &graph, long source, long sink){
  long long maxFlow = 0;
  std::vector<long> foundPath (graph.size());
  while (bfs(graph, source, sink, foundPath)){

    long long pathFlow = 1 << 29;
    for(long v = sink; v != source; v = foundPath[v]){
      pathFlow = std::min(pathFlow,  graph[foundPath[v]][v]);
    }

    for(long v = sink; v != source; v = foundPath[v]){
      long u = foundPath[v];
      graph[u][v] -= pathFlow;
      graph[v][u] += pathFlow;
    }

    maxFlow += pathFlow;
  }
  return maxFlow;
}

int main(void){
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  long N, M, S, T;
  std::cin >> N >> M >> S >> T;

  std::vector<std::vector<long long>> graph(N, std::vector<long long>(N, 0));
  std::vector<std::vector<long long>> orgGraph(N, std::vector<long long>(N, 0));
  for(long i = 0; i < M; i++){
    long long U, V;
    long long C;
    std::cin >> U >> V >> C;
    graph[U][V] = C;
    orgGraph[U][V] = C;
  }

  long long maxFlow = edmondsKarp(graph, S, T);

  std::vector<std::pair<int, int>> ans;
  long usedEdges = 0;
  for (long i = 0; i < N; i++){
    for (long j = 0; j < N; j++){
      if(graph[i][j] != orgGraph[i][j] && orgGraph[i][j] > 0){
        usedEdges++;
        ans.emplace_back(i,j);
      }
    }
  }

  std::cout << N << ' ' << maxFlow << ' ' << usedEdges << '\n';
  for (std::pair<long, long> e: ans){
    long u = e.first, v = e.second;
    std::cout << u << ' ' << v << ' ' << orgGraph[u][v] - graph[u][v] << '\n';
  }

  return 0;
}
