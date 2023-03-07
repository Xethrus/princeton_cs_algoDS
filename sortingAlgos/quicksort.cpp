#include <iostream>
#include <vector>
int partition(std::vector<int> v, int lo, int hi) {
  int i = lo, j = hi+1;
  while(true) {
    while(v[++i] < v[lo]) {
      if(i == hi) break;
    }
    while(v[lo] < v[--j] {
      if(j == lo) break;
    }
    if(i >= j) break;
    v[i] = swap;
    v[i] = v[j];
    v[j] = swap;
  }
}

class Quick

int main() {
  return 0;
}
