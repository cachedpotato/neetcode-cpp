#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int eraseOverlappingIntervals(vector<vector<int>>& intervals) {
  //greedy approach
  //remove the one with bigger end value
  //to minimize overlaps

  sort(intervals.begin(), intervals.end());
  int out = 0;
  int leftEnd = intervals[0][1];

  for (int i = 1; i < intervals.size(); i++) {
    if (leftEnd <= intervals[i][0]) {
      leftEnd = intervals[i][1];
    }

    else {
      //greedy approach
      out++;
      leftEnd = leftEnd < intervals[i][1] ? leftEnd : intervals[i][1];
    }
  }
  return out;
}

int main() {
  vector<vector<int>> intervals = {{1, 2}, {1, 4}, {2, 4}};
  std::cout << eraseOverlappingIntervals(intervals) << std::endl;
}