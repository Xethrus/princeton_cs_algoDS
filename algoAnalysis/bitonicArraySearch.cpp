#include <iostream>
#include <vector>

int search(std::vector<int> vector, int number) {
  int begin1 = 0;
  int begin2 = 0;
  int end2 = vector.size()-1;
  int end1 = 0;

  for(int i = 0; i < vector.size(); i++) {
    std::cout << "vector i = " << vector[i] << std::endl;
    std::cout << "vector i+1 = " << vector[i+1] << std::endl;
    if(vector[i] > vector[i+1]) {
      end1 = i;
      begin2 = i;
      break;
      std::cout << "begin2 starts as: " << begin2 << std::endl;
    }
  }
  std::cout << "1begin1: " << begin1 << std::endl;
  std::cout << "2begin2: " << begin2 << std::endl;
  std::cout << "3end1: " << end1 << std::endl;
  std::cout << "4end2: " << end2 << std::endl;
  while(begin1 <= end1 || begin2 <= end2) {
    if(vector[begin1] == number) {
      return begin1;
    }
    if(vector[begin2] == number) {
      return begin2;
    }
    if(vector[end1] == number) {
      return end1;
    }
    if(vector[end2] == number) {
      return end2;
    }
    int mid1 = begin1 + (end1-begin1)/2;
    int mid2 = begin2 + (end2-begin2)/2;

    if(vector[mid2] == number) {
      return mid2;
    } else if(vector[mid2] < number) {
      begin2 = mid2 + 1;
      std::cout << "5begin2: " << begin2 << std::endl;
    } else {
      end2 = mid2 - 1;
      std::cout << "6end2: " << end2 << std::endl;
    }

    if(vector[mid1] == number) {
      return mid1;
    } else if(vector[mid1] < number) {
      begin1 = mid1 + 1;
      std::cout << "7begin1: " << begin1 << std::endl;
    } else {
      end1 = mid1 - 1;
      std::cout << "8end1: " << end1 << std::endl;
    }
  }
  return -1;
}

int main() {
  std::vector<int> vector = {1,2,4,5,6,5,5,5,1};
  std::cout << search(vector, 4) << std::endl;

  return 0;
}
