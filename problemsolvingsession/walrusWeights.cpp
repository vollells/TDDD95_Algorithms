#include <iostream>
#include <vector>

int main(void){
  int N;
  std::cin >> N;
  std::vector<int> weights(N);
  std::vector<bool> results(2001, false);
  results[0] = true;

  for( int i = 0; i<N; i++){
    std::cin >> weights[i];
  }

  for(int i = 0; i < N; i++){

    for (int j = 2001 - weights[i]; j >= 0; j--) {
      if (results[j]) {
        results[j + weights[i]] = true;
      }
    }

  }

  for (int i = 0; i < 1000; i++){
    if (results[1000+i]){
      std::cout << 1000+i << '\n';
      break;
    } else if (results[1000-i]) {
      std::cout << 1000-i << '\n';
      break;
    }
  }
}
