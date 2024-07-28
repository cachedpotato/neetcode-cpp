#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minCostClimbingStairs(vector<int>& cost) {
  int n = cost.size();
  if (n == 1) {
    return cost[0];
  }
  if (n == 2) {
    return min(cost[0], cost[1]);
  }

  //....i, dp2, dp1, n
  for(int i = n - 3; i > -1; i--) {
    cost[i] += min(cost[i + 1], cost[i + 2]);
  }

  return min(cost[0], cost[1]);
}

int main() {
  vector<int> cost = {1, 2, 1, 2, 1, 1, 1};
  cout << minCostClimbingStairs(cost) << endl;
}