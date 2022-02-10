#include <iostream>
#include <vector>
#include "knapsack.h"

Item::Item(int iW, int iV) : w(iW), v(iV){}

void knapsack(int c, std::vector<Item> *items, std::vector<int> *result){
  std::vector<std::vector<int>> v(items->size()+1, std::vector<int>(c+1));

  for (unsigned int i = 0; i <= items->size(); i++){
    for (int w = 0; w <= c; w++) {
      if (i == 0 || w ==0){
        v[i][w] = 0;
      } else if (items->at(i-1).w <= w) {
        v[i][w] = std::max(items->at(i-1).v + v[i-1][w - items->at(i-1).w],
                           v[i-1][w]);
      } else {
        v[i][w] = v[i-1][w];
      }
    }
  }

  int weight = c;
  for (int i = items->size(); i >= 0; i--){
    if (v[i][weight] == 0){
      break;
    }

    if (v[i][weight] != v[i-1][weight]){
      result->push_back(i-1);
      weight -= items->at(i-1).w;
    }
  }

  return;
}

int main(void){
  while(true){
    int n=-1,c=-1;
    std::cin >> c >> n;
    if (n == -1 || n == -1) {
      break;
    }

    std::vector<Item> items;
    for (int i = 0; i < n; i++){
      items.emplace_back<int,int>(0,0);
      std::cin >> items[i].v >> items[i].w;
    }

    std::vector<int> result;
    knapsack(c, &items, &result);

    std::cout << result.size() << '\n';
    for (int index : result) {
      std::cout << index << ' ';
    }
    std::cout << '\n';
  }
  return 0;
}
