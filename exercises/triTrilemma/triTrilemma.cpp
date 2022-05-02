#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

double EPSILON = 0.00001;

double pythagoras(int x1, int y1, int x2, int y2){
  return std::sqrt(std::pow(x2-x1, 2) +
                   std::pow(y2-y1, 2) * 1.0);
}

struct Triangle{
  double a,b,c;

  Triangle(std::vector<int> coords){
    std::vector<double> tmp(3);

    tmp[0] = pythagoras(coords[0], coords[1], coords[2], coords[3]);
    tmp[1] = pythagoras(coords[2], coords[3], coords[4], coords[5]);
    tmp[2] = pythagoras(coords[4], coords[5], coords[0], coords[1]);


    std::sort(tmp.begin(), tmp.end(), std::greater<double>());

    c = tmp[0];
    b = tmp[1];
    a = tmp[2];
  }
};

std::string triType(Triangle tri){
  if (tri.c + EPSILON >= tri.a + tri.b){
    return "not a triangle\n";
  }

  std::string output;

  output += (tri.a == tri.b || tri.b == tri.c || tri.b == tri.c) ? "isosceles " : "scalene ";

  if(std::abs(std::pow(tri.a, 2) + std::pow(tri.b, 2) - std::pow(tri.c, 2)) <= EPSILON){
    output += "right triangle\n";
  } else if (std::pow(tri.a, 2) + std::pow(tri.b, 2) < std::pow(tri.c, 2)){
    output += "obtuse triangle\n";
  } else {
    output += "acute triangle\n";
  }

  return output;
}


int main(){
  int N;
  std::cin >> N;
  for(int i = 0; i < N; i++){
    std::vector<int> input(6);
    for(int j = 0; j < 6; j++){
      std::cin >> input[j];
    }

    std::string output = triType(Triangle(input));

    std::cout << "Case #" << i+1 << ": " << output;
  }
  return 0;
}
