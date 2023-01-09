#include <iostream>
#include <map>


class UnionFind {
  std::map<int, int> hash;
  static const int ARRAY_SIZE = 10;
  const int array[ARRAY_SIZE] = {1,5,3,2,5,6,7,3,9,10};  
  int id[ARRAY_SIZE];
  UnionFind() {
    for(int i = 1; i <= ARRAY_SIZE; i++) {
      id[i-1] = i;
    }
  }
  void bindUnion(int, int);
  bool connected(int, int);
  int find(int);
};

void UnionFind::bindUnion(int p, int q) {
  if(id[p] == id[q]) {
    return;
  }
  for(int i = 0; i < ARRAY_SIZE; i++) {
    if(id[i] == id[q]) {
      int connection = id[p];
      id[i] = connection;
    }
  }
  int connection = id[p];
  id[q] = connection;
}
bool UnionFind::connected(int p, int q) {
  if(id[p] == id[q]) {
    return true;
  } else {
    return false;
  }
}
int UnionFind::find(int p) {
  for(int i = 0; i < ARRAY_SIZE; i++) {
    if(array[i] == p) {
      return id[i];
    }
  }
}


int main() {
  return 0;
}

