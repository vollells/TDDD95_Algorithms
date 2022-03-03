#include <iostream>
#include <vector>
#include <queue>


int main(void){
  long N,T;
  std::cin >> N >> T;

  std::vector<long> result (T, 0);

  std::vector<std::priority_queue<long, std::vector<long>>>
     timeslots(T, std::priority_queue<long, std::vector<long>>());

  for (long i = 0; i < N; i++){
    long ci, ti;
    std::cin >> ci >> ti;
    timeslots[ti].push(ci);
  }


  for(long i = 0; i < T; i++){
    if (!timeslots[i].empty()){
        result[i] = timeslots[i].top();
        timeslots[i].pop();
    }

    while (!timeslots[i].empty()){
      long leastIndex = -1;
      long leastValue = 100000000000;
      for (long j = i-1; j >= 0; j--) {
        if (result[j] < leastValue){
          leastIndex = j;
          leastValue = result[j];
        }
      }

      if (timeslots[i].top() > leastValue){
        result[leastIndex] = timeslots[i].top();
        timeslots[i].pop();
      } else {
        break;
      }
    }
  }

  long maxMoney = 0;
  for( long elem : result){
    maxMoney += elem;
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
