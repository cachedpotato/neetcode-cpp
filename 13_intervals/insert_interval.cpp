#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int> newInterval) {
  //iterate through intervals
  //update result AND the new interval depending on the start/end value

  int newStartIdx = newInterval[0];
  int newEndIdx = newInterval[1];

  vector<vector<int>> out;
  for (int i = 0; i < intervals.size(); i++) {
    //case 1: new end is smaller than start
    if(newEndIdx < intervals[i][0]) {
      //push current new interval
      out.push_back(newInterval);
      //append res of intervals
      //res += intervals[i:]
      copy(intervals.begin() + i, intervals.end(), back_inserter(out));
      return out;
    }

    //case 2: new start is bigger than end
    else if (newStartIdx > intervals[i][1]) {
      //insert preexisting index
      out.push_back(intervals[i]);
    }

    //caser 3: somewhere in between
    else {
      //update new interval (merging)
      newInterval[0] = newInterval[0] < intervals[i][0] ? newInterval[0] : intervals[i][0];
      newInterval[1] = newInterval[1] > intervals[i][1] ? newInterval[1] : intervals[i][1];
    }
  }

  //merge remaining
  out.push_back(newInterval);
  return out;
}

int main() {
  vector<vector<int>> intervals = {
    {1, 2},
    {3, 5},
    {9, 10}
  };
  vector<int> newInterval = {6, 7};
  vector<vector<int>> out = insert(intervals, newInterval);

  std::cout << "[";
  for (const auto& i: out) {
    std::cout << "[" << i[0] << "," << i[1] << "], ";
  }
  std::cout << "]" << std::endl;
}