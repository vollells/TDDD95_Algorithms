#include "iostream"
#include "fenwick-tree.h"

FenwickTree::FenwickTree (long size){
  length = size+1;
  fenwickTree = new long[size+2];
}

FenwickTree::~FenwickTree(){
  delete [] fenwickTree;
}

void FenwickTree::add(long index, long difference) {
  index++;

  while(index <= length) {
    fenwickTree[index] += difference;
    index += (index & -index);
  }
}

long FenwickTree::sum(long index) {
  long sum = 0;
  index++;

  while(index >= 1) {
    sum += fenwickTree[index];
    index -= (index & -index);
  }

  return sum;
}

long FenwickTree::sum(long startIndex, long endIndex) {
  return sum(endIndex) - sum(startIndex-1);
}
