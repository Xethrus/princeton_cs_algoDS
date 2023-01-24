#include <iostream>
#include <algorithm>

void merge(int a[], int low, int mid, int hi) {
  int totalSize = hi + 1;
  int aux[totalSize];
  std::copy(a, a + totalSize, aux); 
  int i = low;
  int j = mid+1;
  for(int k = low; k <= hi; k++) {
    if(i > mid) { 
      a[k] = aux[j++];
    }
    else if (j > hi) { 
      a[k] = aux[i++];
    }
    else if (aux[j] < aux[i]) {
      a[k] = aux[j++];
    } else {
      a[k] = aux[i++];
    }
  }
}

void mergeSort(int a[], int low, int hi) {
  if(low < hi) {
    int mid = [(low + hi)/2];
    mergeSort(a, low, mid);
    mergeSort(a, mid+1, hi);
    merge(a, low, mid, hi);
  }
}
