/*
 * Author: Victor Lells (vicle728)
 * Problem: Rational Arithmetic with fractions.
 * Comments: In the header file.
 */


#include <iostream>
#include "ratNum.h"

int main(void){
  long n;
  std::cin >> n;
  while(n--){
    ratNum<long long> input1, input2;
    char op;
    std::cin >> input1 >> op >> input2;

    ratNum<long long> output;
    switch(op){
    case '+' : output = input1 + input2; break;
    case '-' : output = input1 - input2; break;
    case '*' : output = input1 * input2; break;
    case '/' : output = input1 / input2; break;
    case '<' : std::cout << (input1 < input2) << '\n'; break;
    case '>' : std::cout << (input1 > input2) << '\n'; break;
    default: break;
    }
    std::cout << output << '\n';
  }
}
