#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
#include <math.h>
int trap(std::vector<int> &height) {
  if (height.empty()) {return 0;}

  int l = 0;
  int r = height.size() - 1;
  int maxL = height[l];
  int maxR = height[r];
  int res = 0;

  //alternate between adding from the left and from the right
  //depending on maxL, maxR value
  //the added water volume solely depends on
  //the smaller of the two
  while (l < r) {
    if (maxL < maxR) {
      l++;
      maxL = std::max(maxL, height[l]); 
      res += maxL - height[l];
    } else {
      r--;
      maxR = std::max(maxR, height[r]);
      res += maxR - height[r];
    }
  }

  return res;
}

int main() {
  std::vector<int> height = {0,2,0,3,1,0,1,3,2,1};
  std::cout << trap(height) << std::endl;
}