#include <vector>
#include <iostream>

int search(std::vector<int> &nums, int target) {
  int size = nums.size();
  int l = 0;
  int r = size - 1;
  int m;

  while (l <= r) {
    m = l + (r - l) / 2;
    if (nums[m] == target) {return m;}

    if (nums[l] <= nums[m]) {
      if (nums[l] <= target && target <= nums[m]) {
        //target in left ordered list
        r = m - 1;
      } else {
        l = m + 1;
      }
    } else {
      if (nums[m] <= target && target <= nums[r]) {
        //target in right ordered list
        l = m + 1;
      } else {
        r = m - 1;
      }
    }
  }
  return -1;
}

int main() {
  std::vector<int> nums = {3, 4, 5, 6, 7, 1, 2};
  int target = 1;
  std::cout << search(nums, target) << std::endl;
}