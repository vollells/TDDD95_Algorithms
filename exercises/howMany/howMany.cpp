#include <iostream>
#include <string>


long long countZeros( long long input){
  long long count = 1;
  long long pos = 1;

  while(true){
    long long nInPos = input / pos;
    long long rInPos = input % pos;
    long long zInPos = nInPos / 10;
    nInPos = nInPos % 10;

    if(zInPos == 0) {return count;}

    if(nInPos == 0){
      count += (zInPos-1) * pos + rInPos + 1;
    } else {
      count += zInPos * pos;
    }

    pos *= 10;
  }
  return count;
}

int main(void){
  long long N, M;
  while(true){
    std::cin >> N >> M;
    if(M < 0){break;}

    long long count = 0;

    if (N == 0){
      count = countZeros(M);
    } else {
      count = countZeros(M) - countZeros(N-1);
    }

    std::cout << count << '\n';
  }
}
