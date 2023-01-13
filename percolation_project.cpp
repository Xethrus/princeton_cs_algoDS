#include <iostream>
#include <vector>
#include <stack>

class Node {
public:
  bool isOpen = false;
  Node*[4] connectedNodes;
  Node() {
    for(int i = 0; i < connectedNodes.size(); i++) {
      connectedNodes[i] = nullptr;
    }
  }
};

class Percolation {
public:
  Percolation(int n) {
    //creates grid: n by n
    int n = n;
    nodeArray = new Node*[n][n];
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; i++) {
        Node* newNode = new Node();
        nodeArray[i][j] = newNode;
      }
    }
    //grid should be full with false nodes
  }

  void open(int, int);
  bool isOpen(int, int);
  bool isFull(int, int);
  int numberOfOpenSites();
  bool doesPercolate();
  //optional test client possible
}

void Percolation::open(int x, int y) {
  if(this->nodeArray[x][y]->isOpen == true) {
    return;
  } else {
  this->nodeArray[x][y]->isOpen = true;
  }
}

bool Percolation::isOpen(int x, int y) {
  if(this->nodeArray[x][y]->isOpen) {
    return true;
  } else {
    return false;
  }
}

int Percolation::numberOfOpenSites() {
  int graphSize = this->nodeCount;
  int openCount = 0;
  for(int i = 0; i < this->n; i++) {
    for(int j = 0; j < this->n; j++) {
      if(this->nodeArray[i][j]->isOpen) {
        openCount++;
      }
    }
  }
  return openCount;
}

bool Percolation::doesPercolate() {
  std::stack<Node*> pathway;
  std::vector<bool> visitedNodes;
  bool loopUnbroken = true;
  for(int i = 0; i < this->n; i++) {
    Node* theNode = this->nodeArray[i][0];
    if(theNode->isOpen) {
      pathway.push(theNode);
      loopUnbroken = false;
      break;
    }
  }
  if(loopUnbroken) {
    return false;
  }
  while(!stack.empty()) {
    Node* node = stack.top();
    stack.pop();
    if(!visitedNodes[node]) {
      visitedNodes[node] = true;
      for(
    }

  }
  
}

int main() {
  return 0;
}
