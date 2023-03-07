#include <iostream>
#include <vector>
class Quick {
  int partition(std::vector<int> v, int lo, int hi) {
    int i = lo;
    int j = hi+1;
    while(true) {
      while(v[++i] < v[lo])) {
        if(i == hi) break;
    }
    while(v[lo] < a[--j]) {
      if(j == lo) break;
    }
    
    if(i >= j) break;

      int swap = v[i];
      v[i] = v[j];
      v[j] = swap;
    }
    int swap = v[lo];
    v[lo] = v[j];
    v[j] = swap;
  }
}

int main() {
  return 0;
}
