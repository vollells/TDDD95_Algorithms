#include <iostream>
#include <unordered_map>

int main(void) {
    std::cout << "Hello from a c++ World!" << std::endl;
    std::unordered_map<std::string, std::string> dictionary = {
        {"RED", "#ff0000"},
        {"BLUE", "#0000ff"},
    };

    std::cout << dictionary["RED"] << std::endl;
    return 0;
}
