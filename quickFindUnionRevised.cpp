#include <iostream>

class QuickFindUF {
public:
  int *id;
  int arraySize;
  QuickFindUF(int N) {
    id = new int[N];
    arraySize = N;
    for(int i = 0; i < N; i++) {
      id[i] = i;
    }
  }
  ~QuickFindUF() {
    delete[] id;
  }

  bool connected(int,int);
  void unioner(int, int);
};

bool QuickFindUF::connected(int p, int q) {
  return id[p] == id[q];
}

void QuickFindUF::unioner(int p, int q) {
  int p_id = id[p];
  int q_id = id[q];

  for(int i = 0; i < arraySize; i++) {
    if(id[i] == q_id) {
      id[i] = p_id;
    }
  }
  return;
}

int main() {
  QuickFindUF test(10);
  test.unioner(1,5);
  test.unioner(6,5);
  if(test.connected(1,6)) {
    std::cout << "it is connected" << std::endl;
  }
  return 0;
}
