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

bool is_placeholder(std::string *string) {
  return string->front() == '<' && string->back() == '>';
}

std::string find_string(std::string in_string,
                        std::unordered_map<std::string, std::string> *curr_dict,
                        std::unordered_map<std::string, std::string> *next_dict) {
  if (is_placeholder(&in_string)){
    return in_string;
  } else {
    return find_string(curr_dict->at(in_string), next_dict, curr_dict);
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

    int index=0;
    bool failure = false;
    for (std::string string_temp : input_vector2) {
      std::string key, value;
      std::unordered_map<std::string, std::string> *correct_dict;

      if (is_placeholder(&string_temp) && !is_placeholder(&input_vector1[index])){
        key = string_temp;
        value = input_vector1[index];
        correct_dict = &dict1;
      } else if (!is_placeholder(&string_temp) && is_placeholder(&input_vector1[index])){
        value = string_temp;
        key = input_vector1[index];
        correct_dict = &dict2;
      } else {
        continue;
      }

      if (correct_dict->count(key) == 0){
        correct_dict->operator[](key) = value;
      } else if (correct_dict->at(key) != value){
        failure = true;
        break;
      }

      index += 1;
    }

    if (failure){
      std::cout << "-\n";
    } else {
      for (std::string string : input_vector1){
        std::cout <<  find_string(string, &dict1, &dict2) << " ";
      }
      std::cout << '\n';
    }
  }
}

/*
7
<a> <b> f
<a> <b> <b>
<a> <b> <b>
<a> <b> f
<a> <b> <b>
<b> <b> f
<b> <b> f
<a> <b> <b>
<a> <a> <b> <b> <c> <c> <b>
a <a> <a> <b> <b> <c> <c>
<a> <a> <b> <b> <c> <c> <d> <d>
a <a> <a> <b> <b> <c> <c> a
<a> <a> <b> <b> <c> <c> <d> <d>
<d> <a> <a> <b> a <c> <c> <d>
*/



