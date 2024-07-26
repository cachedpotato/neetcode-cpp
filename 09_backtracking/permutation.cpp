#include <iostream>
#include <vector>

using namespace std;

void dfs(int i, vector<int>& sub, vector<int>& curr, vector<vector<int>>& out) {
  if (sub.empty()) {
    out.push_back(curr);
    return;
  }

  //pick one from any of the remaining
  for (int j = 0, size = sub.size(); j < size; j++) {
    curr.push_back(sub[j]);
    vector<int> copy = sub;
    copy.erase(copy.begin() + j);
    dfs(i + 1, copy, curr, out);
    curr.pop_back();
  }
}

vector<vector<int>> permute(vector<int>& nums) {
  vector<vector<int>> out;
  vector<int> curr;
  int i = 0;

  dfs(i, nums, curr, out);

  return out;
}

int main() {
  vector<int> nums = {1, 2, 3};
  vector<vector<int>> perm = permute(nums);

  std::cout << "[";
  for(const auto &s : perm) {
    std::cout << "[";
    for (const auto &e: s) {
      std::cout << e << ",";
    }
    std::cout << "], ";
  }
  std::cout << "]" << std::endl;
}
