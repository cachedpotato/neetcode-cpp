#include <vector>
#include <iostream>
#include <numeric>

int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost);
int canCompleteCircuitOptimized(std::vector<int>& gas, std::vector<int>& cost);

int main() {
  std::vector<int> gas = {1, 2, 3, 4};
  std::vector<int> cost = {2, 2, 4, 1};

  std::cout << canCompleteCircuit(gas, cost) << std::endl;
  std::cout << canCompleteCircuitOptimized(gas, cost) << std::endl;
}
//////////////////////////////////////////////
int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
  //initial solution
  int len = gas.size();
  for(int i = 0; i < len; i++) {
    int j = i;
    int count = 0;
    int remaining_gas = 0;

    while (count != len) {
      remaining_gas += gas[j % len] - cost[j % len]; //cycle
      if (remaining_gas < 0) {
        break;
      }
      j++;
      count++;
    }
    if (count == len) {return i;}
  }

  return -1;
}

int canCompleteCircuitOptimized(std::vector<int>& gas, std::vector<int>& cost) {
  //O(n) solution
  if (std::accumulate(gas.begin(), gas.end(), 0) < std::accumulate(cost.begin(), cost.end(), 0)) {
    return -1;
  }

  //start point and net gas gain/loss per station is what matters
  //if at any point total gas becomes negative, we need to change the starting point
  int res = 0;
  int total = 0;
  for (int i = 0; i < gas.size(); i++) {
    total += (gas[i] - cost[i]);
    if (total < 0) {
      //reset
      total = 0;
      res= i + 1;
    }
  }
  return res;
}