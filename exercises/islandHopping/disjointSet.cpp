#include "disjointSet.h"


DisjointSet::DisjointSet (long lengthIn){
  length = lengthIn;
  disjointSet = new std::vector<long>();
  for(long i = 0; i < lengthIn; i++){
    disjointSet->push_back(i);
  }
}

DisjointSet::~DisjointSet() { delete disjointSet; }

long DisjointSet::setFind(long element){
  if (disjointSet->at(element) != element){
    disjointSet->at(element) = setFind(disjointSet->at(element));
    return disjointSet->at(element);
  } else {
    return element;
  }
}

void DisjointSet::setUnion(long a, long b){
  if (setFind(a) == setFind(b)){
    return;
  } else {
    disjointSet->at(setFind(b)) = setFind(a);
  }
}
