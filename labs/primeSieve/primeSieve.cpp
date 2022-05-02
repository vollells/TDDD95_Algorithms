#include <iostream>
#include <vector>
#include <utility>

std::pair<long, std::vector<bool>> primeSieve(long N){
  std::vector<bool> result(N, true);
  long count = N-2;
  result[0] = false;
  result[1] = false;
  for(long i = 0; i < N; i++){
    if(result[i]){
      for(long p = 2; p*i < N; p++){
        if(result[i*p]){
          count--;
        }
        result[i*p] = false;
      }
    }
  }

  return  {count, result};
}

int main(void){
  long N, Q;
  std::cin >> N >> Q;

  std::pair<long, std::vector<bool>> result = primeSieve(N+1);

  long query;
  std::cout << result.first << '\n';
  while(Q-- > 0){
    std::cin >> query;
    std::cout << result.second[query] << '\n';
  }
}
