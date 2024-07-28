#include <iostream>

int climbStairs (int n) {
  if (n < 3) {return n;}

  //.....i, dp2, dp1, n
  int dp1 = 1;
  int dp2 = 2;
  for (int i = n - 3; i > -1; i--) {
    int temp = dp2;
    dp2 += dp1;
    dp1 = temp;
  }

  return dp2;
}

int main() {
  for (int n = 3; n < 8; n++) {
    std::cout << "at " << n << ": " << climbStairs(n) << std::endl;
  }
}