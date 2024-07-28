#include <vector>
#include <iostream>
#include <math.h>

int coinChange(std::vector<int>& coins, int amount) {
  std::vector<int> dp(amount + 1, amount + 1);
  dp[0] = 0;

  for (int i = 1; i <= amount; i++) {
    for (int& c: coins) {
      if (i - c >= 0) {
        dp[i] = std::min(dp[i], 1 + dp[i - c]);
      }
    }
  }

  return dp[amount] > amount ? -1 : dp[amount];
}

int main() {
  std::vector<int> coins = {1, 2, 5};
  int amount = 11;

  std::cout << coinChange(coins, amount) << std::endl;
}