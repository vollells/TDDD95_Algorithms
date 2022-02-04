#include "iostream"
#include "fenwick-tree.h"

int main(void){
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  long N;
  std::cin >> N;
  FenwickTree *ft = new FenwickTree(N);
  long *indices = new long[N];

  for (long i = 0; i < N; i++){
    long x;
    std::cin >> x;
    ft->add(i, 1);
    indices[x] = i;
  }

  // Is it +1?
  long fIndex =1;
  long bIndex = N;
  for (long i = 0; fIndex != bIndex+1; i++){
    long swaps = 0;
    if (i % 2 == 0) {
      int index = indices[fIndex];
      ft->add(index, -1);
      swaps = std::max((long) 0, ft->sum(index));
      fIndex++;
    } else {
      int index = indices[bIndex];
      ft->add(index, -1);
      swaps = std::max((long) 0, ft->sum(index, N));
      bIndex--;
    }
    std::cout << swaps << '\n';
  }

  delete ft;
  return 0;
}
