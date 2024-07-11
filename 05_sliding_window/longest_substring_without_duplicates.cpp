#include <string>
#include <algorithm>
#include <iostream>
#include <unordered_set>

int lengthOfLongestSubstring(std::string s) {
  std::unordered_set<char> charSet;
  int l = 0;
  int res = 0;

  for (int r = 0; r < s.size(); r++) {
    while (charSet.find(s[r]) != charSet.end()) {
      charSet.erase(s[l]);
      l++;
    }
    charSet.insert(s[r]);
    res = std::max(res, r - l + 1);
  }
  return res;
}

int main() {
  std::string s = "zxyzxyz";
  int a = lengthOfLongestSubstring(s);
  std::cout << a << std::endl;
}