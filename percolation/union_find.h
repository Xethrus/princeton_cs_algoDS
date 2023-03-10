#include <iostream>

class QuickFindUF {
public:
  int *id;
  int arraySize;
  QuickFindUF(int n) {
    id = new int[n];
    arraySize = n;
    for(int i = 0; i < n; i++) {
      id[i] = i;
    }
  }
  ~QuickFindUF() {
    delete[] id;
  }

  bool connected(int,int);
  void unioner(int,int);
};

bool QuickFindUF::connected(int p, int q) {
  return id[p] == id[q];
}

void QuickFindUF::unioner(int p, int q) {
  int p_id = id[p];
//  std::cout << "id[p] = ";
 // std::cout << id[p] << std::endl;
  int q_id = id[q];
  //std::cout << "id[q] = ";
  //std::cout << id[q] << std::endl;
  for(int i = 0; i < arraySize; i++) {
    if(id[i] == q_id) {
   //   std::cout << "id[i]: " << id[i] << " -> p_id: " << p_id << std::endl;
      id[i] = p_id;
    }
  }
  return;
}

