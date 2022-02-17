#include <iostream>
#include "disjointSet.h"

int main(void) {
  DisjointSet *sets = new DisjointSet(10);

  sets->setUnion(2,5);
  sets->setUnion(2,6);
  sets->setUnion(5,7);

  std::cout << "set with 7, parent 2: " << sets->setFind(7) << '\n';
  std::cout << "set with 1, parent 1: " << sets->setFind(1) << '\n';
}
