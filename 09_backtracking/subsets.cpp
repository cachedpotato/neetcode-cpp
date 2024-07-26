#include <vector>
#include <iostream>
#include <stack>

void dfs(int i, std::vector<int>& nums,  std::vector<int>& curr, std::vector<std::vector<int>>& out) {
  int len = nums.size();
  if (i == len) {
    out.push_back(curr);
    return;
  }

  //I choose this element
  curr.push_back(nums[i]);
  dfs(i + 1, nums, curr, out);

  //or I don't and move to next
  curr.pop_back();
  dfs(i + 1, nums, curr, out);
}

std::vector<std::vector<int>> subets(std::vector<int>& nums) {
  std::vector<std::vector<int>> out;
  std::vector<int> curr;
  int i = 0;

  dfs(i, nums, curr, out);

  return out;
}

int main() {
  std::vector<int> nums = {1, 2, 3};
  std::vector<std::vector<int>> out = subets(nums);

  std::cout << "[";
  for(const auto &s : out) {
    std::cout << "[";
    for (const auto &e: s) {
      std::cout << e << ", ";
    }
    std::cout << "], ";
  }
  std::cout << "]" << std::endl;
}