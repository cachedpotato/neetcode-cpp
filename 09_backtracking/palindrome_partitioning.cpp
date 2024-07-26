#include <vector>
#include <string>
#include <iostream>
using namespace std;

bool isPalindrome(string s) {
  int len = s.size();
  if (len < 2) {return true;}
  int half = len / 2;
  for (int i = 0; i < half; i++) {
    if (s[i] != s[len - 1 - i]) {return false;}
  }
  return true;
}

void dfs(string s, int l, int r, int len, vector<string>& curr, vector<vector<string>>& out) {
  //basically subset problem dfs
  //but with additional checks for palindrome
  if (r == len) {
    int c = 0;
    for (const auto &s: curr) {
      if (!isPalindrome(s)) {return;}
      c += s.size();
    }
    if (c == len) {out.push_back(curr);}
    return;
  }

  //either I splice it here
  string splice = s.substr(l, r - l + 1);
  curr.push_back(splice);
  dfs(s, r + 1, r + 1, len, curr, out);

  //or I move to next
  curr.pop_back();
  dfs(s, l, r + 1, len, curr, out);
}

vector<vector<string>> partition(string s) {
  vector<vector<string>> out;
  vector<string> curr;
  int l = 0; //index
  int r = 0;
  int len = s.size();

  dfs(s, l, r, len, curr, out);

  return out;
}

int main() {
  string s = "aabbczcd";
  for (const auto &subp: partition(s)) {
    for (const auto &p: subp) {
      cout << p << " ";
    }
    cout << endl;
  }
}