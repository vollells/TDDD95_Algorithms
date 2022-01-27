#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "unordered_map"

std::vector<std::string> split (const std::string &s, char delim) {
    std::vector<std::string> result;
    std::stringstream ss (s);
    std::string item;

    while (getline (ss, item, delim)) {
        result.push_back (item);
    }

    return result;
}

bool placeholder(std::string *string) {
  return string->front() == '<' && string->back() == '>';
}

void do_replacement(std::vector<std::string> *pattern,
                    std::string value,
                    std::string placeholder){
  for (unsigned int i=0; i<pattern->size(); i++){
    if (pattern->at(i) == placeholder){
      pattern->operator[](i) = value;
    }
  }
}

int main(void) {
  int n;
  std::cin >> n;
  std::cin.ignore(256, '\n');

  for(int i=0; i<n; i++){
    std::string input;
    std::vector<std::string> input_vector1, input_vector2;
    std::unordered_map<std::string, std::string> dict1, dict2;

    std::getline(std::cin, input);
    input_vector1 = split(input, ' ');
    std::getline(std::cin, input);
    input_vector2 = split(input, ' ');

    if (input_vector1.size() != input_vector2.size()){
      std::cout << "-\n";
      continue;
    }

    bool failure = false;
    bool change = false;
    while (true) {
      change = false;
      for (unsigned int index = 0; index < input_vector1.size(); index++){
        if (placeholder(&input_vector1[index]) && !placeholder(&input_vector2[index])){
          do_replacement(&input_vector1, input_vector2[index], input_vector1[index]);
          change = true;
        } else if (!placeholder(&input_vector1[index]) && placeholder(&input_vector2[index])){
          do_replacement(&input_vector2, input_vector1[index], input_vector2[index]);
          change = true;
        }
      }

      if (change) {continue;}
      change = false;

      for (unsigned int index = 0; index < input_vector1.size(); index++) {
        if (placeholder(&input_vector1[index]) && placeholder(&input_vector2[index])){
          std::string tmp1 = input_vector1[index];
          std::string tmp2 = input_vector2[index];
          do_replacement(&input_vector1, "kekw", tmp1);
          do_replacement(&input_vector2, "kekw", tmp2);
          change = true;
        }
      }

      if (change) {continue;}

      for (unsigned int i=0; i<input_vector1.size(); i++){
        if (input_vector1[i] != input_vector2[i]){
          failure = true;
        }
      }

      break;
    }


    if (failure){
      std::cout << "-\n";
    } else {
      for (std::string string : input_vector1){
        std::cout <<  string << " ";
      }
      std::cout << '\n';
    }
  }

  return 0;
}


