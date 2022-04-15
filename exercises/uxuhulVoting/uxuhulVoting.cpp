#include <iostream>
#include <vector>

void possibleMove(int index, int* result){
  int i = 0;
  if ((index & 3) != index){
    result[i++] = (index & 3);
  }
  if ((index & 5) != index){
    result[i++] = (index & 5);
  }
  if ((index & 6) != index){
    result[i++] = (index & 6);
  }
  if ((index | 1) != index){
    result[i++] = (index | 1);
  }
  if ((index | 2) != index){
    result[i++] = (index | 2);
  }
  if ((index | 4) != index){
    result[i++] = (index | 4);
  }
}

std::vector<std::vector<int>> pref;
std::vector<std::vector<int>> cahce;

int uxuhul(int stone, int priest, int m){
  if (priest == m){
    return stone;
  }

  if (cahce[priest][stone] != -1){
    return cahce[priest][stone];
  }

  int pos[3];
  possibleMove(stone, pos);

  int res[3];
  for(int i = 0; i < 3; i++){
    res[i] = uxuhul(pos[i], priest+1, m);
  }

  if(pref[priest][res[0]] < pref[priest][res[1]] && pref[priest][res[0]] < pref[priest][res[2]]){
    cahce[priest][stone] = res[0];
    return res[0];
  }else if(pref[priest][res[1]] < pref[priest][res[0]] && pref[priest][res[1]] < pref[priest][res[2]]) {
    cahce[priest][stone] = res[1];
    return res[1];
  }else {
    cahce[priest][stone] = res[2];
    return res[2];
  }

}

int main(void){
  int n;
  std::cin >> n;
  for (int i = 0; i < n; i++){
    int m;
    std::cin >> m;
    pref = std::vector<std::vector<int>>(m, std::vector<int>(8));
    cahce = std::vector<std::vector<int>>(m+1, std::vector<int>(8, -1));

    for(int i = 0; i < m; i++){
      for (int j = 0; j < 8; j++){
        std::cin >> pref[i][j];
      }
    }

    int result = uxuhul(0, 0, m);

    char output[3];
    output[0] = (result & 4) ? 'Y' : 'N';
    output[1] = (result & 2) ? 'Y' : 'N';
    output[2] = (result & 1) ? 'Y' : 'N';
    std::cout << output << '\n';
  }

  return 0;
}


