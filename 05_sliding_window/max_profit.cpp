#include <iostream>
#include <vector>
#include <algorithm>

int maxProfit(std::vector<int> &prices) {
  int size = prices.size();
  int i = 0;
  int profit = 0;

  for(int j = 0; j < size; j++) {
    profit = std::max(profit, prices[j] - prices[i]);
    if (prices[j] < prices[i]) {
      i = j;
    }
  }
  
  return profit;
}

int main() {
  std::vector<int> prices = {10, 1, 5, 6, 7, 1};
  std::cout << maxProfit(prices) << std::endl;
}