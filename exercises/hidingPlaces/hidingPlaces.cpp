#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>

struct Cell{
  int x, y, dist;
  Cell(int iX = 0, int iY = 0, int iD = -1) : x(iX), y(iY), dist(iD){}
};

std::vector<Cell> adjacentEdges(std::vector<std::vector<Cell>> &mapp, Cell curr){
  std::vector<Cell> result;
  if(curr.x >= 2 && curr.y <= 6){
    result.push_back(mapp[curr.y+2][curr.x-1]);
  }
  if(curr.x <= 7 && curr.y <= 6){
    result.push_back(mapp[curr.y+2][curr.x+1]);
  }
  if(curr.x <= 6 && curr.y <= 7){
    result.push_back(mapp[curr.y+1][curr.x+2]);
  }
  if(curr.x <= 6 && curr.y >= 2){
    result.push_back(mapp[curr.y-1][curr.x+2]);
  }
  if(curr.x <= 7 && curr.y >= 3){
    result.push_back(mapp[curr.y-2][curr.x+1]);
  }
  if(curr.x >= 2 && curr.y >= 3){
    result.push_back(mapp[curr.y-2][curr.x-1]);
  }
  if(curr.x >= 3 && curr.y >= 2){
    result.push_back(mapp[curr.y-1][curr.x-2]);
  }
  if(curr.x >= 3 && curr.y <= 7){
    result.push_back(mapp[curr.y+1][curr.x-2]);
  }
  return result;
}

int main(void){
  int N;
  std::cin >> N;

  std::unordered_map<char, int> charToInt = {{'a', 1}, {'b', 2}, {'c', 3},
                                             {'d', 4}, {'e', 5}, {'f', 6},
                                             {'g', 7}, {'h', 8}};
  std::unordered_map<int, char> intToChar = {{1, 'a'}, {2, 'b'}, {3, 'c'},
                                             {4, 'd'}, {5, 'e'}, {6, 'f'},
                                             {7, 'g'}, {8, 'h'}};

  while(N > 0){
    std::queue<Cell, std::deque<Cell>> Q;
    std::vector<std::vector<Cell>> mapp(9, std::vector<Cell>(9));

    for(int i = 1; i < 9; i++){
      for(int j = 1; j < 9; j++){
        mapp[j][i] = Cell(i, j);
      }
    }

    char coords[2];
    std::cin >> coords;
    Q.push(Cell(charToInt[coords[0]], coords[1] - '0', 0));
    mapp[Q.front().y][Q.front().x] = Cell(Q.front().x, Q.front().y, 0);

    while(!Q.empty()){
      Cell curr = Q.front();
      Q.pop();
      std::vector<Cell> validNeighbours = adjacentEdges(mapp, curr);
      for(Cell next : validNeighbours){
        if(mapp[next.y][next.x].dist == -1){
          mapp[next.y][next.x].dist = curr.dist +1;
          Q.push(mapp[next.y][next.x]);
        }
      }
    }

    int maxDist = 0;
    for(int i = 1; i < 9; i++){
      for(int j = 8; j > 0; j--){
        if(maxDist < mapp[j][i].dist){
          maxDist = mapp[j][i].dist;
        }
      }
    }
    std::cout << maxDist << ' ';
    for(int j = 8; j > 0; j--){
      for(int i = 1; i < 9; i++){
        if (mapp[j][i].dist == maxDist){
          std::cout << intToChar[i] << j << ' ';
        }
      }
    }
    std::cout << '\n';
    N--;
  }

  return 0;
}
