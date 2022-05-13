/*
   Author: Victor Lells
   Problem: Erathostenes Prime Sieve
   TC: Check each function
   How To Run: Compile and run!
*/

#include <iostream>
#include <vector>
#include <utility>

/*
 * Algo: We go thorugh all numbers up to N and check their multiples
 * up to N.
 *
 * Input :
 * - N : The largest number to be calculated.
 *
 * Output: A pair with Number of prime numbes below including N and a
 * bool array to see if a particualr number is prime.
 *
 * TC: ~log(N) as we only check each multiple of a number which when
 * i=2 is max N/2 times.
 *
 * MC: O(N).
 */
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

// Kattis problem specific, not relevant.
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
