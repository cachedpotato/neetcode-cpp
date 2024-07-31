#include <vector>
#include <iostream>

int jump(std::vector<int>& nums) {
  int res = 0;
  int l = 0;
  int r = 0;

  //bfs
  while (r < nums.size()) {
    int temp = r;
    for (int i = l; i <= temp; i++) {
      r = r < i + nums[i] ? i + nums[i] : r;
    }
    l = temp + 1;
    res++;
  }

  return res;
}

int main() {
  std::vector<int> nums = {2, 3, 1, 1, 4, 5, 6};

  std::cout << jump(nums) << std::endl;
}