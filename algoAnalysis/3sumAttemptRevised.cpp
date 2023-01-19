#include <iostream>
#include <vector>

std::vector<int> vec = {-40,-30,-20,-20,-10,0,10,20,30,40,40,40};

void getZeroSum(std::vector<int> vec) {
  int count = 0;
  for(int i = 0; i < vec.size(); i++) {
    int next = i+1;
    int rear = vec.size()-1;
    int targetVal = -vec[i];
    while(next < rear) {
      if(vec[next] + vec[rear] == targetVal) {
        std::cout << "target val: " << targetVal << std::endl;
        std::cout << vec[next] << " and " << vec[rear] << std::endl;
        count++;
        while(next < rear && vec[next] == vec[next+1]) next++;
        while(next < rear && vec[rear] == vec[rear-1]) rear--;
        next++;
        rear--;
      }
      else if(vec[next] + vec[rear] < targetVal) {
        next++;
      }
      else {
        rear--;
      }
    }
  }
  std::cout << count << std::endl;
}

int main() { 
  getZeroSum(vec);
}
