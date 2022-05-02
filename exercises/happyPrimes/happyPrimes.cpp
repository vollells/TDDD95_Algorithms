#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <utility>

std::vector<bool> primeSieve(long N){
  std::vector<bool> result(N, true);
  result[0] = false;
  result[1] = false;
  for(long i = 0; i < N; i++){
    if(result[i]){
      for(long p = 2; p*i < N; p++){
        result[i*p] = false;
      }
    }
  }

  return result;
}

long happyNumber(long long input){
  std::string value = std::to_string(input);
  long long output = 0;
  for(char c: value){
    output += ((c - '0') * (c - '0'));
  }
  return output;
}

bool happyPrime(long long input, std::unordered_set<long long> visited){
  long long nextNumber = happyNumber(input);
  if(visited.count(nextNumber) == 1){
    return false;
  } else if (nextNumber == 1){
    return true;
  } else {
    visited.emplace(nextNumber);
    return happyPrime(nextNumber, visited);
  }
}

int main(void){
  long N;
  std::cin >> N;
  std::vector<bool> primeList = primeSieve(10001);
  while(N--){
    long long K, M;
    std::cin >> K >> M;

    if (primeList[M] && happyPrime(M, std::unordered_set<long long>())){
      std::cout << K << ' ' << M << " YES\n";
    } else {
      std::cout << K << ' ' << M << " NO\n";
    }

  }
}
