#include <iostream>
#include <vector>
#include <stack>
#include "eulerianPath.h"

std::vector<long> eulerianPath(Graph<long> graph){
  std::vector<long> result;
  long first=-1, end=-1;

  // Check for odd in/out.
  for (long i = 0; i < graph.N; i++){
    long inSize = graph.inEdges[i].size();
    long outSize = graph.outEdges[i].size();
    if (first == -1 &&  inSize == outSize - 1){
      first = i;
    }  else if (end == -1 && inSize - 1 == outSize) {
      end = i;
    } else if (inSize != outSize) {
      return std::vector<long>();
    }
  }

  // XOR - Either both are -1 or neither is.
  if (!!((first == -1) != (end == -1)) ){
    return std::vector<long>();
  }

  std::stack<long> stack;
  long curr = (first != -1) ? first : 0;

  // Algo.
  while(!graph.outEdges[curr].empty() || !stack.empty()){
    if(graph.outEdges[curr].empty()){
      result.push_back(curr);
      curr = stack.top();
      stack.pop();
    } else {
      stack.push(curr);
      long tmp = curr;
      curr = graph.outEdges[curr].top().endNode;
      graph.outEdges[tmp].pop();
    }
  }
  result.push_back(curr);

  // Check for disconnections.
  for (long i = 0; i < graph.N; i++){
    if(graph.outEdges[i].size() != 0){
      return std::vector<long>();
    }
  }

  return result;
}

int main(void){
  while(true){
    long N=0,M=0;
    std::cin >> N >> M;

    if(N+M == 0){break;}

    Graph<long> graph(N);

    for(long i = 0; i < M; i++){
      long U, V;
      std::cin >> U >> V;
      graph.addEdge(U,V);
    }

    std::vector<long> result = eulerianPath(graph);

    if (result.empty()){
      std::cout << "Impossible\n";
    } else {
      for (long i = result.size()-1; i >= 0; i--){
        std::cout << result[i] << ' ';
      }
      std::cout << '\n';
    }
  }

  return 0;
}
