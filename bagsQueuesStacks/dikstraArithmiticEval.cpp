#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <cmath>


template <typename T>
class Node {
public:
  T data;
  Node* next;
  
  Node(T data) {
    this->data = data;
    next = nullptr;
  }
};

template <typename T>
class Stack {
public:
  Node<T>* top;
  int totalSize;
  Stack() {
    top = nullptr;
  }
  void push(T);
  T pop();
};


template <typename T>
void Stack<T>::push(T element) {
Node<T>* newNode = new Node<T>(element);
  if(this->top == nullptr) {
    this->top = newNode;
    return;
  } else {
    Node<T>* placeHolder = this->top;
    this->top = newNode;
    newNode->next = placeHolder;
    return;
  }
}

template <typename T>
T Stack<T>::pop() {
  Node<T>* placeHolder = this->top;
  this->top = this->top->next;
  return placeHolder;
}

class ArithmaticDualStack {
public:
  Stack<int> operandStack;
  Stack<char> operatorStack;

  double solveInput();
};

double ArithmaticDualStack::solveInput() {
  std::cout << "enter you arithmatic: ";
  std::string equation;
  std::getline(std::cin, equation);

  for(int i = 0; i < equation.size() - 1; i++) {
    std::vector<int> number;
    number.clear();
    while(std::isdigit(equation[i])) {
      number.push_back(equation[i]);
      i++;
    }
    if(!number.empty()){ 
      int numberPlaces = number.size();
      int theNumber = 0;
      for(int i = 0; i < numberPlaces; i++) {
        int multi = std::pow(10,i);
        theNumber += number[numberPlaces-i] * multi;
      }
      this->operandStack.push(theNumber);
    }
    switch(equation[i]) {
      case "+": this->operatorStack->push('+');
      case "-": this->operatorStack->push('-');
      case "*": this->operatorStack->push('*');
      case "/": this->operatorStack->push('/');

    }
    if(equation[i] == ")") {
      switch(this->operandStack->pop()) {
        case '+': this->operandStack->push(
          (this->operandStack->pop() + this->operandStack->
            pop()));
        case '-': this->operandStack->push(
          (this->operandStack->pop() - this->operandStack->
            pop()));
        case '*': this->operandStack->push(
          (this->operandStack->pop() * this->operandStack->
            pop()));
        case '/': this->operandStack->push(
          (this->operandStack->pop() / this->operandStack->
            pop()));
      }
    }
  }
  return this->operandStack->pop();
}

};


int main() {
  return 0;
}
