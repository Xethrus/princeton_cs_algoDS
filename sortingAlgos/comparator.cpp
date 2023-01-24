#include <iostream>
#include <vector>
#include <string>

class User {
  std::string first_name;
  std::string last_name;
  int id;
  User(std::string fname, std::string lname, int id) {
    first_name = fname;
    last_name = lname;
    id = id;
  }
public:
  void userCreation(std::string fname, std::string lname, int id) {
    if(fname.size() < 0) {
      std::cerr << "non-func input first name" << std::endl;
      return;
    }
    if(lname.size() < 0) {
      std::cerr << "non-func input last name" << std::endl;
      return;
    }
    if(id < 0) {
      std::cerr << "non-func id" << std::endl;
      return;
    }
    User(fname, lname, id);
  }
  bool goesFirst(User secondUser) {
    bool rate; 
    if(this->first_name[0] <= secondUser->first_name[0]) {
      if(this->last_name[0] < secondUser->last_name[0]) {
        return true;
      }
    }
  }
}
