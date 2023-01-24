#include <iostream>
#include <vector>

void merge(std::vector<int>& v, int lo, int mid, int hi) { //merge method used to combine the vector/array together
  std::vector<int> aux; //auxilary vector so we can sort in place
  for(int i = 0; i < hi+1; i++) { //filling aux vector with a std::copy like functionality
    aux.push_back(v[i]); //pushing back the ith index of the original vector
  }
  int i = lo; //setting integer i = to the passed in low (to function as a point of reference)
  int j = mid+1; //setting integer j = to mid + 1, setting it to the beginning of the "right vector" mid is the end of left vector so mid + 1 is the right vector beginning, both i and j function as pointers that help our movement and manipulation in the vector
  for(int k = lo; k <= hi; k++) { //for loop using to iterate from point lo to hi usin k
    if(i > mid) { //checking if i is greater than it the highest element of its vector, meaning it has completed all of it's elements
      v[k] = aux[j++]; //this sets kth index of vector to j and then increments j to move it to the next components
    } else if(j > hi) { //checking if j is greater than its maximum element of its vector, meaning it has gone through all it's items
      v[k] = aux[i++]; //this sets kth index of vector to the ith element of the auxilary vector and then increments i to a new item
    } else if(aux[j] < aux[i]) { //this checks to see if jth element of aux is less than the ith element of aux, if so then we set the kths element of vector to the jth element of auxilary and then increment j, (we want the lowest numbers first so that is our fall through case)
      v[k] = aux[j++]; 
    } else { //this is the opposite of the above effect, setting the kth element of v to the ith element of auxilary then incrementing i
      v[k] = aux[i++];
    }
  }
}

void mergeSort(std::vector<int>& v, int lo, int hi) { //take in a vector "v" and its beginning and end
  if(lo < hi) { //checks if lo is less than hi, which it is until the base case where lo and hi are the same thing
    int mid = ((lo + hi)/2); //calculates the middle of the vector with floor devision, this division sides on the lower side
    mergeSort(v, lo, mid); //recalls merge sort with a the left sub vector calling lo the beginning and mid the end
    mergeSort(v, mid+1, hi); //recalls merge sort with a right sub vector calling mid+1 the beginning and hi the end
    merge(v, lo, mid, hi);  //calls merge to combine and "sort" the sub vectors created.
  }
  return; // it is done calculating  this can be envisioned as a large tree of nodes, pittering down to a base care return where lo = hi
}


int main() {
  std::vector<int> vectr = {4,5,12,4,21,412,24,214,124,412,12,3};
  mergeSort(vectr, 0, vectr.size());
  for(int i = 0; i < vectr.size(); i++) {
    std::cout << vectr[i] << std::endl;
  }
}
