#include <stack>
#include <math.h>
#include <iostream>

class MinStack {
private:
    std::stack<int> stack = {};
    std::stack<int> minStack = {};

public:
  MinStack() {}

  void push(int val) {
    stack.push(val);
    int currMin = std::min(val, minStack.empty() ? val : minStack.top());
    minStack.push(currMin);
  }

  void pop() {
    stack.pop();
    minStack.pop();
  }

  int top() {
    return stack.top();
  }

  int getMin() {
    return minStack.top();
  }
};

int main() {
  MinStack minStack;
  minStack.push(1);
  minStack.push(2);
  minStack.push(0);
  std::cout << minStack.getMin() << std::endl; // return 0
  minStack.pop();
  std::cout << minStack.top() << std::endl;    // return 2
  std::cout << minStack.getMin() << std::endl; // return 1
}