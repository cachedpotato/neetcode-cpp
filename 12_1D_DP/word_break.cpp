#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

bool wordBreak(string s, vector<string>& wordDict) {
  vector<bool> dp(s.size() + 1, false);
  dp[s.size()] = true;

  for (int i = s.size() - 1; i > -1; i--) {
    for (const auto& w: wordDict) {
      if ((i + w.size()) <= s.size() && s.substr(i, w.size()) == w) {
        dp[i] = dp[i + w.size()];
      }

      if (dp[i]) {
        break;
      }
    }
  }

  return dp[0];
}

int main() {
  string s = "neetcode";
  vector<string> wordDict = {"code", "neet", "leet"};
  cout << wordBreak(s, wordDict) << endl;

}