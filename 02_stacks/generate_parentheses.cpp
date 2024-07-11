#include <iostream>
#include <vector>
#include <string>

class Solution {
private: 
  void backtrack(int n, int open, int close, std::string current, std::vector<std::string>& out) {
    if (current.length() == n * 2) {
      out.push_back(current);
      return;
    }

    if (open < n) {
      backtrack(n, open + 1, close, current + "(", out);
    }

    if (open > close) {
      backtrack(n, open, close + 1, current + ")", out);
    }

    return;
  }


public:
  std::vector<std::string> generateParentheses(int n) {
    std::vector<std::string> out = {};

    backtrack(n, 0, 0, "", out);

    return out;
  }
};

int main() {

  Solution solution;
  std::vector<std::string> res;
  res = solution.generateParentheses(3);

  std::cout << "[";
  for (auto &r: res) {
    std::cout << r << ",";
  }
  std::cout << "]" <<std::endl;

}

