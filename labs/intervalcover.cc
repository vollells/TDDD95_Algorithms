#include <iostream>
#include <vector>
#include <algorithm>

struct interval{
  int index;
  double start;
  double end;
  bool operator < (const interval& i) const { return (start < i.start); }
};

/* Test case with every case i can imagine. (Have tested with big ints and decimals).
0 10
12
-3 -2
-2.5 1
0 5
0 6
4 7
4 7
6 10
6 10
9.5 14
13 14
13 14
22 23
2
3 6
*/

std::vector<int> cover(interval interval_goal, std::vector<interval> *intervals){

  std::sort(intervals->begin(), intervals->end());
  std::vector<int> cover = {};

  interval covered = {-1, interval_goal.start, interval_goal.start };
  int sorted_index = 0;
  for (interval inter : *intervals){
    /*
      Case 1: If same pos/earlier and better!
      Case 2: If after the previous start add as new refrence!
    */
    if (inter.start <= covered.start && ((cover.empty() && inter.end >= covered.end)||
                                         (!cover.empty() && inter.end > covered.end))){
      if (!cover.empty()){
        cover.pop_back();
      }
      covered.end = inter.end;
      cover.push_back(intervals->at(sorted_index).index);
    } else if (inter.start <= covered.end && inter.end > covered.end){
      covered.start = covered.end;
      covered.end = inter.end;
      cover.push_back(intervals->at(sorted_index).index);
    }

    /* Stop at the fist occurance of a valid result */
    if (covered.end >= interval_goal.end){
      break;
    }
    sorted_index++; 
  }

  // If we did not cover the entire goal interval return empty.
  if (covered.end < interval_goal.end){
    return std::vector<int>();
  }

  return cover;
}

int main(void) {
  double start,end;
  while(std::cin >> start >> end){
    struct interval interval_goal = {0, start, end};

    std::vector<interval> intervals;
    int n;
    std::cin >> n;
    for (int j = 0; j < n; j++){
      double start,end;
      std::cin >> start >> end;
      struct interval inter = {j, start, end};
      intervals.push_back(inter);
    }

    std::vector<int> output;
    output = cover(interval_goal, &intervals);

    if (output.empty()) {
      std::cout << "impossible" << std::endl;
    } else {
      std::cout << output.size() << std::endl;
      for (auto a : output){
        std::cout << a << " ";
      }
      std::cout << std::endl;

    }
  }
}

