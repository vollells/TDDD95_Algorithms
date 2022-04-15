/*
 * Author: Victor Lells (vicle728)
 * Problem: Longest Increasing Subsequence
 * Comments: Look in header file.
 */

#include <iostream>
#include <vector>
#include <cmath>

std::vector<long> lis(std::vector<long> seq, long N){
  std::vector<long> seqPred(N);
  std::vector<long> lengthIndex(N + 1);

  long L = 0;
  for (long i = 0; i < N; i++){
    long lo = 1;
    long hi = L + 1;
    while(lo < hi){
      long mid = lo + std::floor((float)(hi-lo)/2.0);
      if(seq[lengthIndex[mid]] < seq[i]){
        lo = mid + 1;
      } else {
        hi = mid;
      }
    }

    long newL = lo;
    seqPred[i] = lengthIndex[newL-1];
    lengthIndex[newL] = i;

    if (newL > L){
      L = newL;
    }
  }

  std::vector<long> result(L);
  long k = lengthIndex[L];
  for (long i = L-1; i >= 0; i--){
    result[i] = k;
    k = seqPred[k];
  }
  return result;
}

int main(void) {
  while(true){
    long N = -1;
    std::cin >> N;

    if(N == -1){break;}

    std::vector<long> seq(N);
    long n;
    for(long i = 0; i < N; i++){
      std::cin >> n;
      seq[i] = n;
    }

    std::vector<long> result = lis(seq, N);

    std::cout << result.size() << '\n';
    for(long l : result){
      std::cout << l << ' ';
    }
    std::cout << '\n';
  }

  return 0;
}
