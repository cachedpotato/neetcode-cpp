#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>

int characterReplacement(std::string s, int k) {
  int result = 0;
  int maxFrequency = 0;
  std::vector<int> charFreq(26, 0);

  int l = 0;
  int r = 0;
  while (r < s.size()) {
    //update frequency
    charFreq[s[r] - 'A']++;
    maxFrequency = std::max(maxFrequency, charFreq[s[r] - 'A']);

    //if window - maxFrequencyChar > k: revalidate window
    while (r - l + 1 - maxFrequency > k) {
      //remove left side freq
      charFreq[s[l] - 'A']--;
      l++;
    }

    //if valid - update result
    result = std::max(result, r - l + 1);
    r++;
  }
  return result;
}

int main() {
  std::string s = "AAABABB";
  int k = 1;
  std::cout << characterReplacement(s, k) << std::endl;
}