#include <iostream>
#include <vector>

class Solution {
public:
  std::vector<int> productExceptSelf(std::vector<int>& nums) {
    std::vector<int> res;
    auto len = nums.size();
    int left[len];
    left[0] = 1;
    int right[len];
    right[len - 1] = 1;

    for (int i = 1; i < len; i++) {
      left[i] = left[i-1] * nums[i - 1];
    }
    for (int j = len - 2; j > -1; j--) {
      right[j] = right[j + 1] * nums[j + 1];
    }

    for(int i = 0; i < len; i++) {
      res.push_back(left[i] * right[i]);
    }

    return res;

  }

};

int main() {
  std::vector<int> nums = {1, 2, 4, 6};
  Solution solution;

  std::vector<int> products = solution.productExceptSelf(nums);
  for (auto n: products) {
    std::cout << n << std::endl;
  }
}