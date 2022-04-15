#include <iostream>
#include <string>
#include <unordered_map>

bool isValid(std::string s) {
  std::unordered_map<char, int> counter;
  for(char c : s){
    if(!counter.emplace(c, 1).second)
      counter[c] += 1;
  }

  int count = 0;
  for(auto kv : counter)
    if(kv.second % 2 != 0)
      count++;

  return count < 2;
}

int countSwap(std::string s){

  int strlen = (int) s.size();
  int count = 0;
  int i = 0;

  while (i < strlen/2){

    int right = strlen - i- 1;
    while (i < right){
      if (s[i] == s[right]){
        break;
      } else {
        right--;
      }
    }

    if (i == right){
      std::swap(s[i], s[i+1]);
      count++;
    } else {
      for (int j = right; j < strlen - i - 1; j++){
        std::swap(s[j], s[j+1]);
        count++;
      }
      i++;
    }
  }

  return count;
}

int main(void){
  int n;
  std::cin >> n;
  while(n-- > 0){
    std::string input;
    std::cin >> input;

    if(!isValid(input)){
      std::cout << "Impossible" << '\n';
    } else {
      int result = countSwap(input);
      std::cout << result << '\n';
    }

  }

  return 0;
}
