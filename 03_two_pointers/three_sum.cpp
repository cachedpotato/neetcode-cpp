#include <vector>
#include <iostream>
#include <algorithm>

std::vector<std::vector<int>> threeSum(std::vector<int>& nums){
  std::sort(nums.begin(), nums.end());
  int size = nums.size();
  std::vector<std::vector<int>> out = {};


  for (int i = 0; i < size; i++) {
    if (nums[i] > 0) {break;}
    if (i > 0 && nums[i] == nums[i - 1]) {continue;}

    int l = i + 1;
    int r = size - 1;
    int twoSum = -nums[i];

    while (l < r) {
      if (nums[l] + nums[r] < twoSum) {
        l += 1;
      } else if (nums[l] + nums[r] > twoSum) {
        r -= 1;
      } else {
        int curr = nums[l];
        out.push_back({nums[i], nums[l], nums[r]});
        r -= 1;
        while (l < r && nums[l] == curr) {
          l += 1;
        }
      }
    }
  }

  return out;
}

int main() {
  std::vector<int> nums = {-1,0,1,2,-1,-4};
  
  std::cout << "[";
  for(auto &r: threeSum(nums)) {
    std::cout << "[";
    for (auto &n : r) {
      std::cout << n << ",";
    }
    std::cout << "], ";
  }
  std::cout << "]" << std::endl;
}
