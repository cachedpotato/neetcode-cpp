#include <vector>
#include <iostream>

int maxSumSubarray(std::vector<int>& nums) {
  int maxSum = nums[0];
  int currSum = 0;

  //Kadane's Algorithm
  for (const int& n: nums) {
    currSum = currSum < 0 ? 0 : currSum;
    currSum += n;
    maxSum = maxSum < currSum ? currSum : maxSum;
  }

  return maxSum;
}

int main() {
  std::vector<int> nums = {1 ,2, -1, 4, -6, 7, 8};
  std::cout << maxSumSubarray(nums) << std::endl;
}