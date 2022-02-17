#include <iostream>
#include <vector>
#include <queue>


int main(void){
  long N,T;
  std::cin >> N >> T;

  std::vector<std::priority_queue<long, std::vector<long>>>
     timeslots(T, std::priority_queue<long, std::vector<long>>());

  for (long i = 0; i < N; i++){
    long ci, ti;
    std::cin >> ci >> ti;
    timeslots[ti].push(ci);
  }

  long maxMoney = 0;
  for (long i= 0; i < T; i++){
    long nPT = -1;
    for (long j = i; j < T; j++){
      if (!timeslots[j].empty()){
        nPT = j;
        break;
      }
    }
    if (nPT == -1){
      break;
    }
    maxMoney += timeslots[nPT].top();
    timeslots[nPT].pop();
  }

  std::cout << maxMoney << '\n';
}


// for (long i = 0; i < N; i++){
//   long j = 0;
//   std::cout << "Timeslot: " << i << '\n';
//   while(!timeslots[i].empty()){
//     std::cout << timeslots[i].top() << ' ';
//     timeslots[i].pop();
//     j++;
//   }
//   std::cout << '\n';
// }
