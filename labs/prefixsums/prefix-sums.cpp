/*
   Author: Victor Lells
   Problem: Fenwick Tree
   TC: Check each function
   How To Run: Compile and run!
*/
#include "iostream"

/*
 * Function: Return the sum of all previous elements by traversing the tree,
 * parents are defined as element with the next lower twos complement. Start
 * at 1 and go to index.
 *
 * Use: Give the Fenwick Tree (Long array) and get sum.
 *
 * Input :
 * - *fw : pointer to the first element of a fenwick tree
 * - index : the last (inclusive) element to include in output.
 *
 * Output:
 * - long: the sum of elements 0...i
 *
 * TC: log(n) with n number of elements.
 */
long sum(long *fw, long index)
{
   long sum = 0;
   index++;

   while(index > 0)
   {
      sum = sum + fw[index];
      index -= index & (-index);
   }
   return sum;
}

/*
 * Function: Traverse fenwick tree from index and change node(index) and all
 * ancestors with value newVal.
 *
 * Use: Give the Fenwick Tree (Long array) and get sum.
 *
 * Input :
 * - *fw : pointer to the first element of a fenwick tree
 * - length : length of array
 * - index : the first (inclusive) element to reduce/increase.
 * - newVal : The offset which element index should have.
 *
 * Output:
 * - void: the sum of elements 0...i
 *
 * TC: log(n) with n number of elements.
 */
void add(long *fw, long length, long index, long newVal)
{
   index++;
   while (index <= length)
   {
      fw[index] += newVal;
      index += index & (-index);
   }
}

// Kattis problem specific, not relevant.
int main(void){
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  long N, Q;
  std::cin >> N >> Q;

  // The fenwick tree.
  long *ft = new long[N+1];

  for (long i = 0; i < Q; i++) {
    char c;
    std::cin >> c;

    if (c == '+'){
      long index, diff;
      std::cin >> index >> diff;
      add(ft, N, index, diff);

    } else if (c == '?'){
      long index;
      std::cin >> index;
      if (index == 0) {
        std::cout << index << '\n';
      } else {
        std::cout << sum(ft, --index) << '\n';
      }

    }
  }

  delete[] ft;
  return 0;
}
