#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;

int numDecodings(string s) {
  unordered_map<int, int> dp;
  int len = s.size();
  dp[len] = 1;
  string zeroToTen = "0123456";

  for (int i = len - 1; i > -1; i--) {
    //case 1: i is zero
    if (s[i] == '0') {
      dp[i] = 0; //no way of decoding
    }

    //case 2: i is 1 - 9
    else {
      dp[i] = dp[i + 1];
    }

    //case 3: 2 digit
    if (i + 1 < len) {
      if (
        s[i] == '1' ||//s[i+1] can be anythinga
        s[i] == '2' && zeroToTen.find(s[i + 1]) != std::string::npos  //20~26
      ) {
        dp[i] += dp[i + 2];
      }
    }
  }

  return dp[0];
}

int main() {
  string s = "12";
  cout << numDecodings(s) << endl;
}