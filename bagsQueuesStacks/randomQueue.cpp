#include <iostream>
#include <random>
#include <ctime>
template <typename T>
class RandomQueue {
  struct Node {
    Node* next;
    Node* prev;
    T data;
    Node(T info) {
      data = info;
    }
  };
  Node* _oldest;
  Node* _newest;
  int totalSize;
public:
  RandomQueue() {
    Node* _oldest = nullptr;
    Node* _newest = nullptr;
    totalSize = 0;
  }
  bool isEmpy() {
    if(_oldest == nullptr) {
      return true;
    } else {
      return false;
    }
  }
  int getSize() {
    return this->totalSize;
  }
  void enqueue(T item) {
    Node* newNode = new Node(item);
    if(_newest == nullptr) {
      this->_newest = newNode;
      this->_oldest = newNode;
      this->increaseSize();
    } else {
      newNode->next = this->_newest;
      this->_newest = newNode;
      this->increaseSize();
    }
  }
  T& dequeue() {
    if(_newest == nullptr) {
      std::cerr << "FAILURE NULLPTR ONLY AVALIABLE"
        << std::endl;
    } else {
      std::cout << "this->getSize():" << this->getSize() << std::endl;
      int chance = this->getSize();
      std::mt19937 engine(std::time(nullptr));
      std::uniform_int_distribution<int> dist(0,chance);
      int movement = dist(engine);
      std::cout << "start movement: " << movement << std::endl;
      Node* cursor = this->_newest;
      for(int i = 1; i < movement; i++) {
        cursor = cursor->next;
      }
      T& item = cursor->data;
      return item;
    }
  }

  void increaseSize() {
    this->totalSize++;
  }
  class Iter {
    Node* node;
    Iter(Node* node) {
      node(node);
    }

    T& operator*() {
      return node->data;
    }
    Iter& operator++() {
      node = node->next;
    }
    Iter& operator--() {
      node = node->prev;
    }
    bool operator!=(const Iter& other) {
      return node != other.node;
    }
    Iter begin() {
      return Iter(_newest);
    }
    Iter end() {
      return Iter(nullptr);
    }
  };

};

int main() {
  RandomQueue<int> test;
  test.enqueue(1);
  test.enqueue(2);
  test.enqueue(3);
  test.enqueue(4);
  test.enqueue(5);
  std::cout << test.dequeue() << std::endl;
  return 0;
}
