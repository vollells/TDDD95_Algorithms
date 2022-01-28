#include <iostream>
#include <limits.h>
#include <string>
#include <cstring>

char (*move)[1001];
int (*height_cache)[1001];
int *heights;
int *m;

int distance_calc(int curr_height = 0, int curr_index = 0){
  if (curr_height < 0) {
    return INT_MAX;
  } else if (curr_index == *m) {
    return (curr_height == 0) ? curr_height : INT_MAX;
  } else if (height_cache[curr_index][curr_height] != -1){
    return height_cache[curr_index][curr_height];
  }

  int u_height = distance_calc(curr_height + heights[curr_index], curr_index+1);
  int d_height = distance_calc(curr_height - heights[curr_index], curr_index+1);

  if (u_height > d_height) {
    move[curr_index][curr_height] = 'D';
    height_cache[curr_index][curr_height] = std::max(d_height, curr_height);
  } else if (u_height <= d_height) {
    move[curr_index][curr_height] = 'U';
    height_cache[curr_index][curr_height] = std::max(u_height, curr_height);
  }

  return height_cache[curr_index][curr_height];
}

int main(void){
  int n;
  std::cin >> n;
  for (int i = 0; i<n ; i++){
    m = new int;
    std::cin >> *m;
    heights = new int[*m];
    for (int j = 0; j<*m ; j++){
      std::cin >> heights[j];
    }

    move = new char[40][1001];
    height_cache = new int[40][1001];
    memset(height_cache, -1, sizeof(height_cache[0][0]) * 40 * 1001);

    int distance = distance_calc();

    if (distance == INT_MAX){
      std::cout << "IMPOSSIBLE\n";
    } else {
      distance = 0;
      std::string output = "";

      for (int k=0; k<*m; k++){
        output.push_back(move[k][distance]);
        distance += (move[k][distance]=='U') ? heights[k] : -heights[k];
      }
      std::cout << output << '\n';
    }

    delete[] move;
    delete[] height_cache;
    delete[] heights;
    delete m;

  }

  return 0;
}

