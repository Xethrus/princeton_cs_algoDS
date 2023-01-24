#include <iostream>
#include <vector>

std::vector<int> mergeSort(std::vector<int> v) {
  int mid, totalSize;
  totalSize = v.size();
  mid = totalSize/2;
  int start1, end1, start2, end2;
  start1 = 0;
  end1 = mid-1;
  start2 = mid;
  end2 = totalSize-1;
  std::vector<int> aux;
  for(int k = start1; k <= end2; k++) {
    aux[k] = v[k];
  }
  int i, j;
  i = start1;
  j = start2;
  for(int k = start1; k <= end2; k++) {
    if(start1 > start2) { v[k] = aux[j++]; }
    else if(j > end2) { v[k] = aux[i++]; }
    else if(aux[j] < aux[i]) {
      v[k] = aux[j++];
    } else {
      v[k] = aux[i++];
    }
  }
  return aux;
}

int main() {
  return 0;
}
