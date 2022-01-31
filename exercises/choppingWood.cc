#include <iostream>
#include <queue>

void tree(long n, long *nodes, long *result){
  /* How many connections each node has left. Need to be n+2 as index
     0 is ignored and we need to account for n+1 node numbers */
  long *connections = new long[n+2];

  for(long i = 0; i<n; i++){
    long node_index = nodes[i];
    connections[node_index]++;
  }

  std::priority_queue<long, std::vector<long>, std::greater<long>> pq;

  for(long i = 1; i<n+1; i++){
    if (connections[i] == 0){
      pq.push(i);
    }
  }

  for (long i=0; i<n; i++){
    if(pq.empty()){
      result[0] = -1;
      return;
    }

    long node_index = nodes[i];
    connections[node_index]--;

    result[i] = pq.top();
    pq.pop();

    if(connections[node_index] == 0){
      pq.push(node_index);
    }
  }
}

int main(void){
  long n;
  std::cin >> n;

  // Contains the list v.
  long *node_v = new long[n];
  long *node_u= new long[n];

  for(int i=0; i<n; i++){
    int x;
    std::cin >> x;
    node_v[i] = x;
  }

  tree(n, node_v, node_u);

  if (node_u[0] == -1) {
    std::cout << "Error\n";
  } else {
    for(int i=0; i<n; i++){
      std::cout << node_u[i] << "\n";
    }
  }
}
