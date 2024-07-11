#include <iostream>
#include <vector>
#include <math.h>

int findMin(std::vector<int> &nums) {
  int size = nums.size();
  int l = 0;
  int r = size - 1;
  int res = nums[l];

  int m;
  while (l <= r) {
    if (nums[l] < nums[r]) {
      //l - m - r complete sort
      //l is the smallest
      res = std::min(nums[l], res);
      break;
    }
    m = l + (r - l) / 2;
    res = std::min(res, nums[m]);
    if (nums[l] <= nums[m]) {
      //m currently at left sorted array
      //move to the right
      l = m + 1;
    } else {
      //m currently at right sorted array
      //move to the left
      r = m - 1;
    }
  }

  return res;
}

int main() {
  std::vector<int> nums = {3, 4, 6, 1, 2};
  std::cout << findMin(nums) << std::endl;
}