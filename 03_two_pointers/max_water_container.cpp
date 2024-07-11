#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int maxArea(vector<int>& heights) {
  int size = heights.size();
  int l = 0;
  int r = size - 1;
  int maxWater = 0;

  while (l < r) {
    maxWater = max(maxWater, (r - l) * min(heights[l], heights[r]));
    if (heights[l] < heights[r]) {
      int currL = heights[l];
      while (l < r && heights[l] <= currL) {
        l++;
      }
    } else {
      int currR = heights[r];
      while (l < r && heights[r] <= currR) {
        r--;
      }
    }
  }
  return maxWater;
}

int main() {
  vector<int> height = {1, 7, 2, 5, 4, 7, 3, 6};
  cout << maxArea(height) << endl;
}