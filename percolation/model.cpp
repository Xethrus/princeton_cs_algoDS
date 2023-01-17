#include "union_find.h"
#include "node.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

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
    
    checker = new QuickFindUF(n * n);

    gridSize = n;
    int count = 0;
    for(int y = 0; y < n; y++) {
      for(int x = 0; x < n; x++) {
        Node* newNode = new Node();
        nodeArray[x][y] = newNode;
        newNode->xyCord = std::make_pair(x,y);  
        if(x == 0) {
          topNodes.push_back(newNode);
          //std::cout << newNode->xyCord.first << " and " <<
          //  newNode->xyCord.second << std::endl;
        }
        if(y == n-1) {
          bottomNodes.push_back(newNode);
          //std::cout << newNode->xyCord.first << " and " <<
          //  newNode->xyCord.second << std::endl;
        }
        count++;
        std::cout << count << std::endl;
        newNode->number = count;
      }
    }
  }

  void open(int, int);
  bool isOpen(int, int);
  int openSites();
  bool percolates();
  void nodeOpenChance(float);
  //test funcs
  void testIdArray();
  void testNodeArrayTopAndBottom();
  void testPrintCords(int, int);
  void testOpenSitesCount();
  void testPrintOpenSiteNum();
  void testPrintGrid();
};
//test
void Percolation::testIdArray() {
  int fullSize = gridSize * gridSize;
  std::cout << "--------------------" << std::endl;
  std::cout << "id array test" << std::endl;
  for(int i = 0; i < fullSize; i++) {
    std::cout << this->checker->id[i] << std::endl;
  }
  std::cout << "id array test concluded" << std::endl;
  std::cout << "--------------------" << std::endl;
}
void Percolation::testNodeArrayTopAndBottom() {
  std::cout << "--------------------" << std::endl;
  std::cout << "top array start" << std::endl;
  for(int i = 0; i < this->topNodes.size(); i++) {
    std::cout << "index: " << i <<
      " topNode: " << topNodes[i]->number << std::endl;
  }
  std::cout << "top array end" << std::endl;
  std::cout << "------------------" << std::endl;
  std::cout << "bottom array start" << std::endl;
  for(int i = 0; i < this->bottomNodes.size(); i++) {
    std::cout << "index: " << i <<
      " bottomNode: " << bottomNodes[i]->number << std::endl;
  std::cout << "--------------------" << std::endl;
  }
  std::cout << "bottom array end" << std::endl;
}
void Percolation::testPrintCords(int x, int y) {
  std::cout << "--------------------" << std::endl;
  std::cout << "testing cord" << std::endl;
  std::cout << "cordinate: " << x << "," << y <<
    std::endl;
  std::cout << this->nodeArray[x][y]->number <<
    std::endl;
  std::cout << "end of testing cord" << std::endl;
  std::cout << "--------------------" << std::endl;
}
void Percolation::testOpenSitesCount() {
  std::cout << "--------------------" << std::endl;
  std::cout << "number of open sites" << std::endl;
  std::cout << this->openSites() << std::endl;
  std::cout << "--------------------" << std::endl;
}
void Percolation::testPrintOpenSiteNum() {
  std::vector<int> numbersThatAreOpen;
  for(int y = 0; y < gridSize; y++) {
    for(int x = 0; x < gridSize; x++) {
      if(this->nodeArray[x][y]->isOpen) {
        numbersThatAreOpen.push_back(this->
          nodeArray[x][y]->number);
      }
    }
  }
  std::cout << "open sites" << std::endl;
  std::cout << "----------" << std::endl;
  for(const int e : numbersThatAreOpen) {
    std::cout << e << std::endl;
  }
  std::cout << "open sites ended" << std::endl;
  std::cout << "----------------" << std::endl;
}
void Percolation::testPrintGrid() {
  for(int y = 0; y < gridSize; y++) {
    std::cout << std::endl;
    for(int x = 0; x < gridSize; x++) {
      std::cout << 
        this->nodeArray[x][y]->number
        << " ";
    }
  }
}
//

void Percolation::open(int x, int y) {
  Node* current = this->nodeArray[x][y];
  Node* up =  nullptr;
  if(y < this->gridSize-1) {
    up = this->nodeArray[x][y+1];
  } else {
    up = nullptr;
  }
  Node* down = nullptr;
  if(y >= 1) {
    down = this->nodeArray[x][y-1];
  } else {
    down = nullptr;
  }
  Node* right = nullptr;
  if(x < this->gridSize-1) {
    right = this->nodeArray[x+1][y];
  } else {
    right = nullptr;
  }
  Node* left = nullptr;
  if(x >= 1) {
    left = this->nodeArray[x-1][y];
  } else {
    left = nullptr;
  }

  if(!current->isOpen) {
    current->isOpen = true;
  }
  if(up) {
    if(up->isOpen) {
      this->checker->unioner(up->xyCord.first,up->xyCord.second);
    }
  }
  if(down) {
    if(down->isOpen) {
      this->checker->unioner(down->xyCord.first,down->xyCord.second);
    }
  }
  if(right) {
    if(right->isOpen) {
      this->checker->unioner(right->xyCord.first,right->xyCord.second);
    }
  }
  if(left) {
    if(left->isOpen) {
      this->checker->unioner(left->xyCord.first,left->xyCord.second);
    }
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
      if(this->nodeArray[x][y]->isOpen) {
        openCount++;
      }
    }
  }
  return openCount;
}

bool Percolation::percolates() {
  int sizeOfCurrent = this->checker->arraySize;
  for(int y = 0; y < this->topNodes.size(); y++) {
    for(int x = 0; x < this->bottomNodes.size(); x++) {
      std::cout << "top Node id: ";
      std::cout << this->checker->id[this->topNodes[y]->
          number] << std::endl;
      std::cout << "bottom Node id: ";
      std::cout << this->checker->id[this->bottomNodes[x]->
          number] << std::endl;
      if(this->checker->id[this->topNodes[y]->number] ==
         this->checker->id[this->bottomNodes[x]->number]) {
        std::cout << "yay" << std::endl;
        return true;
      }
    }
  }
  std::cout << "nay" << std::endl;
  return false;
}
bool chance(float percent) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(0,1);
  return dis(gen) <= percent;
}
void Percolation::nodeOpenChance(float percent) {
  for(int y = 0; y < this->gridSize; y++) {
    for(int x = 0; x < this->gridSize; x++) {
      if(chance(percent)) {
        std::cout << "opening node" <<
          this->nodeArray[x][y]->number <<
          std::endl;
        this->open(x,y);
      }
    }
  }
}

int main() {
  Percolation test(5);
  test.testPrintOpenSiteNum();
  test.nodeOpenChance(.70);
  test.testPrintOpenSiteNum();
  test.testPrintGrid();
  test.testIdArray();
  test.percolates();
  return 0;
}
