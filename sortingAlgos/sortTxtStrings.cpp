#include <iostream>
#include <vector>
#include <fstream>
#include <string>

std::vector<std::string> parseToVec(std::string component) {
  std::cout << " " << std::endl;
  std::cout << "line recieved" << component << std::endl;
  std::cout << " " << std::endl;
  std::vector<std::string> ofWords;
  std::string word;
  for(int i = 0; i < component.size(); i++) {
    if(component[i] = ' ' && word.size() > 0) {
      std::cout << "pushing word: " << word << std::endl;
      ofWords.push_back(word);
      word.clear();
    } else {
      word.push_back(component[i]);
      std::cout << "pushing letter: " << component[i] << std::endl;
      
    }
  }
  return ofWords;
}
int main(int argc, char* argv[]) {
  if(argc < 2) {
    std::cerr << "no input" << std::endl;
    return 1;
  }
  std::string file_name = argv[1];
  std::fstream file(file_name);
  if(file.is_open()) {
    std::string line;
    std::vector<std::string> allWords;
    while(std::getline(file, line)) {
      std::cout << "line: " << line;
      std::vector<std::string> newWords;
      newWords = parseToVec(line);
      allWords.insert(allWords.end(), newWords.begin(),
        newWords.end());
    }
    for(auto i : allWords) {
      std::cout << i << std::endl;
    }
    file.close();
  } else {
    std::cerr << "failed to open file: " << file_name << std::endl;
  }
  return 0;
}

