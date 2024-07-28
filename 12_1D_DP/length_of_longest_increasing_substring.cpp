#include <iostream>
#include <vector>
#include <algorithm>

int lengthofLIS(std::vector<int>& nums) {
  int len = nums.size();
  std::vector<int> dp(len, 1);
  
  for (int i = len; i > -1; i--) {
    for (int j = i + 1; j < len; j++) {
      if (nums[i] < nums[j]) {
        dp[i] = std::max(dp[i], 1 + dp[j]);
      }
    }
  }

  return dp[0];

}

int main() {
  std::vector<int> nums = {1, 2, 4, 3, 2, 2, 6, 6, 8};
  std::cout << lengthofLIS(nums) << std::endl;
}