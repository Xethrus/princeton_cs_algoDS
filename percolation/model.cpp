#include "union_find.h"
#include "node.h"
#include <iostream>
#include <vector>
#include <algorithm>

class Percolation {
public:
  std::vector<std::vector<Node*>> nodeArray;
  QuickFindUF* checker;
  std::vector<Node*> topNodes;
  std::vector<Node*> bottomNodes;
  int gridSize = 0;
  Percolation(int n) {
    std::vector<std::vector<Node*>> newArray(n, std::vector<Node*>(n));
    nodeArray = newArray;
    checker = new QuickFindUF(n);

    gridSize = n;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        Node* newNode = new Node();
        nodeArray[i][j] = newNode;
        newNode->xyCord = std::make_pair(i,j);  
        if(j == 0) {
          topNodes.push_back(newNode);
          std::cout << newNode->xyCord.first << " and " <<
            newNode->xyCord.second << std::endl;
        }
        if(j == n-1) {
          bottomNodes.push_back(newNode);
          std::cout << newNode->xyCord.first << " and " <<
            newNode->xyCord.second << std::endl;
        }
      }
    }
  }

  void open(int, int);
  bool isOpen(int, int);
  int openSites();
  bool percolates();
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

bool Percolation::isOpen(int x, int y) {
  if(this->nodeArray[x][y]->isOpen) {
    return true;
  } else {
    return false;
  }
}

int Percolation::openSites() {
  int openCount = 0;
  for(int y = 0; y < this->gridSize; y++) {
    for(int x = 0; x <this->gridSize; x++) {
      if(!this->nodeArray[x][y]->isOpen) {
        openCount++;
      }
    }
  }
  return openCount;
}

bool Percolation::percolates() {
  int sizeOfCurrent = this->checker->arraySize;
  for(int i = 0; i < this->topNodes.size(); i++) {
    for(int j = 0; j < this->bottomNodes.size(); j++) {
      if(this->checker->id[this->topNodes[i]->number] ==
         this->checker->id[this->bottomNodes[j]->number]) {
        std::cout << "yay" << std::endl;
        return true;
      }
    }
  }
  std::cout << "nay" << std::endl;
  return false;
}

int main() {
  Percolation test(5);
  
  return 0;
}
