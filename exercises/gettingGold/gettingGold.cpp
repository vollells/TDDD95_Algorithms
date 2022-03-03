#include <iostream>
#include <vector>
#include <string>
#include <queue>

struct Cell{
  int x;
  int y;
  char c;
  bool e;
  Cell(int iX = 0, int iY = 0, char iC = ' ', bool iE = false) : x(iX), y(iY), c(iC), e(iE){}
};

std::vector<Cell> adjacentEdges(std::vector<std::vector<Cell>> &mapp, Cell curr, int W, int H){
  std::vector<Cell> result;

  bool trap = false;
  for(int i = -1; i <= 1; i++){
    for (int j = -1; j <= 1; j++){
      if (i != j && i != -j){
        // std::cout << "i: " << i << " j: " << j << '\n';
        if (mapp[curr.y+i][curr.x+j].c == 'T'){
          return std::vector<Cell>();
        }
        if (mapp[curr.y+i][curr.x +j].c != '#' && !mapp[curr.y +i][curr.x + j].e){
          result.push_back(mapp[curr.y+i][curr.x+j]);
        }
      }
    }
  }
  return result;
}

int main(void){
  int W, H;
  std::cin >> W >> H;
  std::vector<std::vector<Cell>> mapp(H, std::vector<Cell>(W));
  std::queue<Cell, std::deque<Cell>> Q;

  for(int i = 0; i < H; i++){
    std::string input = {};
    std::cin >> input;
    for(int j = 0; j < W; j++ ){
      Cell tmp = Cell(j, i, input[j], input[j] == 'P');
      if (input[j] == 'P'){
        Q.push(tmp);
      }
      mapp[i][j] = tmp;
    }
  }

  int numberGold = 0;

  while(!Q.empty()){
    Cell curr = Q.front();
    Q.pop();
    if (curr.c == 'G'){
      numberGold++;
    }
    std::vector<Cell> validNeighbours = adjacentEdges(mapp, curr, W, H);
    for(Cell next : validNeighbours){
      mapp[next.y][next.x].e = true;
      Q.push(next);
    }
  }

  std::cout << numberGold;

  return 0;
}

// for(int i = 0; i < H; i++){
//   for(int j = 0; j < W; j++ ){
//     std::cout << mapp[i][j] << ' ';
//   }
//   std::cout <<  '\n';
//  }
