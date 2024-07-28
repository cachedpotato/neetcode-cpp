#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>

int maxProdct(std::vector<int>& nums) {
  int res = nums[0];
  int maxProd = 1; 
  int minProd = 1;

  for (int& n: nums) {
    int temp = maxProd * n;
    maxProd = std::max(std::max(n * maxProd, n * minProd), n);
    minProd = std::min(std::min(temp, n * minProd), n);
    res = std::max(res, maxProd);
  }
  return maxProd;
}

int main() {
  std::vector<int> nums = {1, 2, -3, 4};
  std::cout << "MAX PRODUCT: " << maxProdct(nums) << std::endl;
}