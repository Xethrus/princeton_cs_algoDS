#include "union_find.h"
#include "node.h"
#include <iostream>

class Percolation {
public:
  Percolation(int n) {
    union_find::QuickFindUF* checker = new QuickFindUF(n);
    //the idea i am workin on right now does not account for the full path, it will jump over in between nodes if wanted node gets swapped lol
    int fullSize = n * n;
    array = new Node*[n][n];
    for(int i = 0; i < n; i++) {
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
    checker.union_find::unioner(up->xyCord.first,up->xyCord.second);
  }
  if(down->isOpen) {
    checker.union_find::unioner(down->xyCord.first,down->xyCord.second);
  }
  if(right->isOpen) {
    checker.union_find::unioner(right->xyCord.first,right->xyCord.second);
  }
  if(left->isOpen) {
    checker.union_find::unioner(left->xyCord.first,left->xyCord.second);
  }
}

int main() {
  return 0;
}
