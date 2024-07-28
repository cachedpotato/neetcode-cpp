#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

int rob(vector<int>& nums) {
  //....rob1, rob2, curr, ...
  int rob1 = 0;
  int rob2 = 0;

  for (int i = 0; i < nums.size(); i++) {
    int temp = max(nums[i] + rob1, rob2);
    rob1 = rob2;
    rob2 = temp;
  }

  return rob2;
}

int main() {
  vector<int> nums = {1, 1, 3, 3};
  cout << rob(nums) << endl;
}