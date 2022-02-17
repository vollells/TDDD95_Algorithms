/*
 * Author: Victor Lells (vicle728)
 *
 * Problem: DisjointSet / Union Find problem.
 *
 * Time Complexity: Look at individual functions.
 *
 * Use: Include disjointSet.cpp at compilation.
 */

#include <iostream>
#include "disjointSet.h"


/*
 * Function: main
 *
 * Use: Handles the data input and answer output.
 *
 * TC: N/A - kattis input/output parser.
 */
int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  long N, Q;
  std::cin >> N >> Q;
  DisjointSet *sets = new DisjointSet(N);

  for (int i = 0; i < Q; i++){
    char op;
    long a,b;
    std::cin >> op >> a >> b;
    if (op == '?') {
      if (sets->setFind(a) == sets->setFind(b)){
        std::cout << "yes\n";
      } else {
        std::cout << "no\n";
      }
    } else if (op == '=') {
      sets->setUnion(a, b);
    }
  }

  delete sets;
  return 0;
}


