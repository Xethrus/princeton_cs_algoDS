#include <iostream>
#include <vector>
#include <string>

template <typename Item>
class Node {
public:
  Item data;
  Node* prev;
  Node* next;
  Node() {
    prev = nullptr;
    next = nullptr;
  }
  Node(Item data) {
    this->data = data;
    next = nullptr;
    prev = nullptr;
  }
};

template <typename Item>
class Deque {
public:
  Node<Item>* top;
  Node<Item>* bottom;
  int totalSize = 0;
  
  Deque() {
    totalSize = 0;
    top = nullptr;
    bottom = nullptr;
  }

  bool isEmpty();
  int getSize();
  void pushFirst(Item);
  void pushLast(Item);
  Item popFirst();
  Item popLast();
  void increaseSize();
  //test 
  void testFuctionality();
};

template <typename Item>
void Deque<Item>::increaseSize() {
  this->totalSize = this->totalSize + 1;
}

template <typename Item>
void Deque<Item>::testFuctionality() {
  std::string test1 = "1";
  std::string test2 = "2";
  std::string test3 = "3";
  std::string test4 = "4";
  std::string test5 = "5";
  this->pushFirst(test1);
  if(this->popFirst() == test1) {
    std::cout << "test pushed and popped one node succesfully" << std::endl;
  }
  this->pushLast(test1);
  this->pushFirst(test2);
  this->pushLast(test3);
  //expected state: "2" "1" "3"
  if(this->popFirst() == test2) {
    if(this->popFirst() == test1) {
      if(this->popFirst() == test3) {
        std::cout << "successfully pushed last, front, last, and recieved expected result from three calls to pop first" <<
        std::endl;
      }
    }
  } else {
    std::cout << "failed first item popped" << std::endl;
    std::cout << "expected: " << test2 << std::endl;
  }
}

template <typename Item>
bool Deque<Item>::isEmpty() {
  if(this->top == nullptr) {
    return true;
  }
  if(this->bottom == nullptr) {
    return true;
  }
  return false;
}

template <typename Item>
int Deque<Item>::getSize() {
  return this->totalSize;
}

template <typename Item>
void Deque<Item>::pushFirst(Item data) {
  this->totalSize++;
  std::cout << "totalsize after ++ " << this->totalSize << std::endl;
  Node<Item>* newNode = new Node<Item>(data);
  if(this->isEmpty()) {
    this->top = newNode;
    this->bottom = newNode;
    return;
  }
  Node<Item>* ref = this->top;
  this->top = newNode;
  ref->prev = newNode;
  newNode->next = ref;
  return;
}

template <typename Item>
void Deque<Item>::pushLast(Item data) {
  this->totalSize++;
  std::cout << "totalsize after ++ " << this->totalSize << std::endl;
  Node<Item>* newNode = new Node<Item>(data);
  if(this->isEmpty()) {
    this->bottom = newNode;
    this->top = newNode;
    return;
  }
  this->bottom->next = newNode;
  newNode->prev = this->bottom;
  this->bottom = newNode;
  return;
}

template <typename Item>
Item Deque<Item>::popFirst() {
  this->totalSize--;
  std::cout << "totalsize after -- " << this->totalSize << std::endl;
  if(this->isEmpty()) {
    std::cerr << "Attempting to access Invalid Contents" << std::endl;
  } else if(this->getSize() == 1) {
    Item item = this->top->data;
    this->top = nullptr;
    this->bottom = nullptr;
    return item;
  }
  Item item = this->top->data;
  this->top = this->top->next;
  return item;
}

template <typename Item>
Item Deque<Item>::popLast() {
  this->totalSize--;
  std::cout << "totalsize after -- " <<this->totalSize << std::endl;
  if(this->isEmpty()) {
    std::cerr << "Attempting to access Invalid Contents" << std::endl;
  } else if(this->getSize() == 1) {
    Item item = this->bottom->data;
    this->bottom = nullptr;
    this->top = nullptr;
    return item;
  }
  Item item = this->bottom->data;
  this->bottom = this->bottom->prev;
  return item;
}

int main() {
  Deque<std::string> test;
  test.pushFirst("hi");
  test.testFuctionality();
  return 0;
}
