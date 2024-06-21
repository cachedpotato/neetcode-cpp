#include <iostream>
#include <string>
#include <vector>
//#include <format>

class Solution {
public:
  //ENCODING: LENSTRING#STRING
  std::string encode(std::vector<std::string>& strs) {
    std::string out = "";
    for (auto& s: strs) {
      int len = s.length();
      std::string lens  = std::to_string(len);
      out += lens + "#" + s;
    }

    return out;
  }

  std::vector<std::string> decode(std::string s) {
    std::vector<std::string> res;
    int i = 0;
    while (i < s.length()) {
      std::string word = "";
      std::string lens = "";

      while (s[i] != '#') {
        lens += s[i];
        i += 1;
      }

      i++; //skip first separator

      int len = stoi(lens);
      for (int j = 0; j < len; j++) {
        word += s[i + j];
      }

      res.push_back(word);
      i += len;
    }

    return res;
  }
};

int main() {
  Solution solution;

  std::vector<std::string> teststring = {
    "neet",
    "code",
    "love",
    "you"
  };

  std::string encoded = solution.encode(teststring);

  std::cout << encoded << std::endl;
  
  std::vector<std::string> decoded = solution.decode(encoded);

  for(auto&s : decoded) {
    std::cout << s << std::endl;
  }

}