#include "iostream"
#include "fenwick-tree.h"

int main(void) {
  FenwickTree *ft = new FenwickTree(5);

  for (long i = 1; i < ft->length; i++){
    ft->add(i ,i);
  }

  for (long i = 1; i < ft->length; i++){
    std::cout << ft->sum(i) << '\n';
  }

  std::cout << "1+2+3 = " << ft->sum(1, 3) << '\n';
  std::cout << "2+3+4 = " << ft->sum(2, 4) << '\n';
  std::cout << "2 = " << ft->sum(2, 2) << '\n';

  std::cout << "-------------" << ft->sum(2, 2) << '\n';

  FenwickTree *ft2 = new FenwickTree(5);

  ft2->add(0, -43);
  ft2->add(4, 1);

  std::cout << "index[0] " << ft2->sum(-1) << '\n';
  std::cout << "index[0-4] " << ft2->sum(4) << '\n';

  std::cout << "-------------" << ft->sum(2, 2) << '\n';

  FenwickTree *ft3 = new FenwickTree(10);

  ft3->add(7, 23);
  std::cout << "index[0-7] " << ft3->sum(7) << '\n';
  ft3->add(3, 17);
  std::cout << "index[0-7] " << ft3->sum(7) << '\n';

}
