#include <iostream>
#include <string>

class Node {
public:
  std::string info;
  Node* next;
  Node() {
  }
  Node(std::string data) {
    info = data;
    next = nullptr;
  }
};

class Stack {
public:
  Node* top;
  int totalSize = 0;
  Stack() {
    top = nullptr;
    totalSize = 0;
  }
  void push(std::string);
  std::string pop();
  bool isEmpty();
};

void Stack::push(std::string info) {
  Node* newNode = new Node(info);
  this->totalSize++;
  if(top == nullptr) {
    this->top = newNode;
    return;
  }
  Node* next = this->top;
  this->top = newNode;
  newNode->next = next;
}

std::string Stack::pop() {
  std::string ref = this->top->info;
  this->top = this->top->next;
  return ref;
}

bool Stack::isEmpty() {
  if(top == nullptr) {
    return true;
  }
  return false;
}

int main() {
  Stack test;
  test.push("a");
  test.push("b");
  test.push("c");
  test.push("d");
  test.push("e");
  test.push("f");
  test.push("g");
  std::cout << test.pop() << std::endl;
  std::cout << test.pop() << std::endl;
  std::cout << test.pop() << std::endl;
  std::cout << test.pop() << std::endl;
  std::cout << test.pop() << std::endl;
  std::cout << test.pop() << std::endl;
  std::cout << test.pop() << std::endl;
  return 0;
}
