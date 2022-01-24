#include "iostream"
#include "string"
#include "unordered_map"
#include <vector>
#include <sstream>

std::vector<std::string> split (const std::string &s, char delim) {
    std::vector<std::string> result;
    std::stringstream ss (s);
    std::string item;

    while (getline (ss, item, delim)) {
        result.push_back (item);
    }

    return result;
}

int main(void) {
    std::string row;
    std::unordered_map<std::string, std::string> dict;
    while (getline(std::cin, row) && row != "") {
        std::vector<std::string> vec1;
        vec1 = split(row, ' ');
        dict[vec1[1]] = vec1[0];
    }

    std::string a;
    while (std::cin >> a) {
        if (dict.count(a)){
            std::cout << dict[a] << std::endl;
        } else {
            std::cout << "eh" << std::endl;
        }
    }

    return 0;
}
