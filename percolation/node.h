#include <utility>

class Node {
public:
  std::pair<int, int> xyCord;
  int number;
  bool isOpen;
  //todo maybe add stuff lol
  Node() {
    isOpen = false;
    number = 0;
  }
  ~Node() {
    delete this;
  }
};
