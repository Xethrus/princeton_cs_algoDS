#include <iostream>
#include <string>

class Point {
public:
  int x;
  int y;
  Point() {
    int x = 0;
    int y = 0;
  }
  Point(int x, int y) {
    x = x;
    y = y;
  }

  int compareTo(Point that) {
    if(this->y < that->y) {
      return -1;
    } else if (this->x < that->x && this->y == that->y) {
      return -1;
    } else if (this->x == that->x && this->y == that->y) {
      return 0;
    } else if (this->y > that->y) {
      return 1;
    } else if (this->y == that->y && this->x < that->x) {
      return 1;
    }
  }

  double slopeTo(Point that) {
    x0 = this->x;
    y0 = this->y;
    x1 = that->x;
    y1 = that->y;
    if(y0 == y1 && x0 == x1) {
      std::cerr << "same point given twice" << std::endl;
    }
    if(y0 == y1) {
      std::cerr << "impossible point combination" << std::endl;
    }
    if(x1 == x0) {
      return 0;
    }
    
    double slope = (y1 - y0)/(x1 - x0);
    return slope;
  }

  bool compareSlope() {
    
  }
}
