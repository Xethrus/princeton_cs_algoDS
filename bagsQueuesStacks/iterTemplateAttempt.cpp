//attempting to make a templated iter "generic iter"

#include <iostream>

template <typename T>
class Deque {
private:
  struct Node {
    Node* next;
    Node* prev;
    T data;
    Node(T info) {
      data = info;
      next = nullptr;
    }
  };
  Node* _back;
  Node* _front;
public:
  Deque() {
    _front = nullptr;
    _back = nullptr;
  }
  class Iter {
  public:
    Node* node;
    Iter(Node* node) {
      node(node);
    }
    T& operator*() {
      return node->data;
    }
    Iter& operator++() {
      node = node->next;
      return this;
    }
    Iter& operator--() {
      node = node->prev;
      return this;
    }
    bool operator!=(const Iter& other) {
      return node != other.node;
    }
    Iter begin() {
      return Iter(_front);
    }
    Iter end() {
      return Iter(nullptr); 
    }
  };
  void pushFront(const T& value) {
    Node* newNode = new Node(value);
    if(this->_front == nullptr) {
      this->_front = newNode;
      this->_back = newNode;
      return;
    } else {
      Node* ref = this->_front;
      ref->prev = newNode;
      this->_front = newNode;
      newNode->next = ref;
      return;
    }
  }
  void pushBack(const T& value) {
    Node* newNode = new Node(value);
    if(this->_back == nullptr) {
      this->_back = newNode;
      this->_front = newNode;
      return;
    } else {
      newNode->prev = this->_back;
      this->_back = newNode;
      return;
    }
  }
  T popFront() {
    if(this->_front == nullptr) {
      std::cerr << "ATTEMPTING TO ACCESS NULLPTR" << std::endl;
    } else {
      T value = this->_front->data;
      this->_front = this->_front->next;
      return value;
    }
  }
  T popBack() {
    if(this->_back == nullptr) {
      std::cerr << "ATTEMPTING TO ACCESS NULLPTR" << std::endl;
    } else {
      T value = this->_back->data;
      this->_back = this->_back->prev;
      return value;
    }
  }
};


int main() {
  Deque<int> test;
  test.pushFront(1);
  test.pushFront(1);
  test.pushFront(1);
  test.pushFront(1);
  test.pushFront(1);
  std::cout << test.popFront() << std::endl;
  std::cout << test.popFront() << std::endl;
  std::cout << test.popFront() << std::endl;
  std::cout << test.popFront() << std::endl;
  std::cout << test.popFront() << std::endl;
  std::cout << test.popFront() << std::endl;
  std::cout << test.popFront() << std::endl;
  std::cout << test.popFront() << std::endl;
  std::cout << test.popFront() << std::endl;
  return 0;
}
