#include "union_find.h"
#include "node.h"
#include <iostream>
#include <vector>

class Percolation {
public:
  std::vector<std::vector<Node*>> nodeArray;
  QuickFindUF* checker;
  Percolation(int n) {
    checker = new QuickFindUF(n);
    int fullSize = n * n;
    nodeArray.resize(n);
    for(int i = 0; i < n; i++) {
      nodeArray[i].resize(n);
      for(int j = 0; j < n; i++) {
        Node* newNode = new Node();
        nodeArray[i][j] = newNode;
        newNode->xyCord = std::make_pair(i,j);
      }
    }
  }

  void open(int, int);
};

void Percolation::open(int x, int y) {
  Node* current = this->nodeArray[x][y];
  Node* up = this->nodeArray[x][y+1];
  Node* down = this->nodeArray[x][y-1];
  Node* right = this->nodeArray[x+1][y];
  Node* left = this->nodeArray[x-1][y];

  if(current->isOpen) {
    return;
  } else {
    current->isOpen = true;
  }
  if(up->isOpen) {
    this->checker->unioner(up->xyCord.first,up->xyCord.second);
  }
  if(down->isOpen) {
    this->checker->unioner(down->xyCord.first,down->xyCord.second);
  }
  if(right->isOpen) {
    this->checker->unioner(right->xyCord.first,right->xyCord.second);
  }
  if(left->isOpen) {
    this->checker->unioner(left->xyCord.first,left->xyCord.second);
  }
}

int main() {
  return 0;
}
