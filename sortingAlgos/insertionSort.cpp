#include <iostream>


void insertionSort(int array[], int arraySize) {
  int i , key, j; //declaring vars
  for(i = 1; i < arraySize; i++) { //outer for loop it go through loop: starts at one because first element is assumed ot be sorted lol
    key = array[i]; //assuming that the key is sorted
    j = i-1; //j is set to one behind i which has been sorted
    while(j >= 0 && array[j] > key) { //this while loop iterates the unsorted portion of the arrayex
      array[j+1] = array[j]; //shifts things
      j = j-1; //if they are larger than the current element
    }
    array[j+1] = key; //this inserts the current element into its correct position in the sorted portion of the array.
  }
}
