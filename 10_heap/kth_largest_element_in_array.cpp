#include <vector>
#include <queue>
#include <math.h>
#include <iostream>

int findKthLargest(std::vector<int>& nums, int k ) {
  std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
  for (int &n : nums) {
    minHeap.push(n);
    if (minHeap.size() > k) {
      minHeap.pop();
    }
  }

  return minHeap.top();

}

int main() {
  std::vector<int> nums = {2, 3, 1, 1, 5, 5, 4};
  int k = 3;
  std::cout << findKthLargest(nums, k) << std::endl;
}