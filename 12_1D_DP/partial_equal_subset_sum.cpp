#include <iostream>
#include <vector>
#include <unordered_set>

bool canPartition(std::vector<int>& nums) {
  std::unordered_set<int> dp;
  dp.insert(0);

  int count = 0;
  for (const int& n: nums) {
    count += n;
  }
  if (count % 2 == 1) {return false;}

  for (const int& n: nums) {
    std::unordered_set<int> sums;
    for (const int& c: dp) { 
      if (c + n == count / 2) {return true;}
      sums.insert(c + n);
    }
    sums.insert(n);
    for (const int& n: sums) {
      dp.insert(n);
    }
  }
  return false;
}

int main() {
  std::vector<int> nums = {1, 2, 3, 4};
  
  canPartition(nums) ? std::cout << "can partition" << std::endl : std::cout << "cannot partition" << std::endl;
}