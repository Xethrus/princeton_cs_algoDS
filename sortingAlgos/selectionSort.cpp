#include <iostream>

int array[] = {1,3,6,23,7,9,8,6,3,32,35,212,43,43};

void sort(int* array){
  int minIndex, temp;
  for(int i = 0; i < 14; i++) {
    minIndex = i;
    for(int j = i+1; j < 14; j++) {
      if(array[j] < array[minIndex]) {
        minIndex = j;
      }
    }
    temp = array[minIndex];
    array[minIndex] = array[i];
    array[i] = temp;
  }
  for(int i = 0; i < 14; i++) {
    std::cout << array[i] << std::endl;
  }

}
int main() {
  sort(array);
}
