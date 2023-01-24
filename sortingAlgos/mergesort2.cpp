#include <iostream>

void merge(int a[], int low, int mid, int hi) {
  
}

void mergeSort(int a[], int low, int hi) {
  if(low < hi) {
    int mid = [(low + hi)/2];
    mergeSort(a, low, mid);
    mergeSort(a, mid+1, hi);
    merge(a, low, mid, hi);
  }
}
