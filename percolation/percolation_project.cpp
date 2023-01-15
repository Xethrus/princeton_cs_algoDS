#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>


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
  std::vector<Node*> genStart();
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

std::vector<Node*> Percolation::genStart() {
  std::vector<Node*> startPos;
  for(int i = 0; i < this->n; i++) {
    if(this->nodeArray[i][0]->isOpen) {
      startPos.push_back(this->nodeArray[i][0]);
    }
  }
  return startPos;
}


bool Percolation::doesPercolate() {
  std::vector<Node*> startPositions = this->genStart();
  if(startPositions.empty()) {
    return false;
  } else {
    //do something
  }
}

void DFS(Node* start, vector<vector<Node*>>& adjacentList) {
  stack<Node*> stack;
  vector<bool> visited(adjacentList.size(), false);
  stack.push(start);
  visited[start] = true;
  while(stack.empty()) {
    Node* currentNode = stack.top();
    stack.pop();

    for(Node* neighbor : adjacentList[currentNode]) {
      if(!visited[neighbor]) {
        stack.push(neighbor);
        visited[neighbor] = true;
      }
    }
  }
}


int main() {
  return 0;
}
