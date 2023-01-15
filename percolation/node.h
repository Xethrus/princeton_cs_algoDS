class Node {
public:
  bool isOpen;
  //todo maybe add stuff lol
  Node() {
    isOpen = false;
  }
  ~Node() {
    delete this;
  }
};
