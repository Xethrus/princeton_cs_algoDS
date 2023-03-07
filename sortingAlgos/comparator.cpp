#include <iostream>
#include <vector>
#include <string>

template <typename T>
bool greaterThan(T a, T b) {
  return a > b;
}
template <typename T>
bool lessThan(T a, T b) {
  return a < b;
}

class name {
public:
  std::string characters;

  name(std::string name) {
    characters = name;
  }

  bool lessThan(name name2) {

  }



};

int main() {
  return 0;
}
