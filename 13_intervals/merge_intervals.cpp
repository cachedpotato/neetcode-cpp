#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
  //sort intervals
  sort(intervals.begin(), intervals.end());
  vector<vector<int>> out;
  vector<int> leftInterval = intervals[0];

  for(int i = 1; i < intervals.size(); i++) {
    if (leftInterval[1] < intervals[i][0]) {
      out.push_back(leftInterval);
      leftInterval = intervals[i];
    }

    else {
      //merge
      leftInterval = {leftInterval[0], max(leftInterval[1], intervals[i][1])};
    }
  }

  out.push_back(leftInterval);
  return out;
}

int main() {
  vector<vector<int>> intervals = {{1, 2}, {2, 3}, {5, 6}, {8, 11}, {9, 10}};
  std::cout << "[";
  for(const auto &v: merge(intervals)) {
    std::cout << "[" << v[0] << "," << v[1] << "]";
  }
  std::cout << "]" << std::endl;
}