#include <iostream>
#include <vector>

void mergeSort(std::vector<int> v) {
  std::vector<int> halveOne;
  std::vector<int> halveTwo;
  int totalSize = v.size();
  int midPoint = totalSize/2;
  for(int i = 0; i < totalSize; i++) {
    if(i < midPoint) {
      halveOne.push_back(v[i]);
    } else {
      halveTwo.push_back(v[i]);
    }
  }
  std::vector<int> halveOneSorted = selectionSort(halveOne);
  std::vector<int> halveTwoSorted = selectionSort(halveTwo);
}

std::vector selectionSort(std::vector<int> v) {
  int min;
  for(int i = 0; i < v.size(); i++) {
    min = i;
    for(int j = i; j < v.size(); j++) {
      if(v[j] < v[min]) {
        min = j;
      }
    }
    swap = v[min];
    v[min] = v[i];
    v[i] = swap;
  }
}


int main() {
  return 0;
}
