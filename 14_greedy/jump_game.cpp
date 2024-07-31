#include <vector>
#include <iostream>

bool canJump(std::vector<int>& nums) {
  int goal = nums.size() - 1;

  for (int i = goal - 1; i > -1; i--) {
    //from back, move the GOAL to the left
    if (i + nums[i] >= goal) {
      goal = i;
    }

  }

  //see if we can start from 0
  return goal == 0;
}

int main() {
  std::vector<int> nums = {1, 2, 0, 1, 0};

  canJump(nums) ? std::cout << "yes" << std::endl : std::cout << "no" << std::endl;
}