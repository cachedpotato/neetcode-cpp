#include <vector>
#include <iostream>
#include <algorithm>

class Interval {
public:
  int start, end;
  Interval(int start, int end): start(start), end(end) {}
};

int minMeetingRooms(std::vector<Interval>& intervals);

int main() {
  Interval one(0, 40);
  Interval two(5, 10);
  Interval three(15, 20);

  std::vector<Interval> intervals = {one, two, three};
  std::cout << minMeetingRooms(intervals) << std::endl;
}

/////////////////////////////////////////////////////////////////

int minMeetingRooms(std::vector<Interval>& intervals) {
  //recursion with remainders
  //except for recursion - same with erase overlapping interval

  if (intervals.size() == 0) {return 0;}
  int out;
  std::vector<Interval> remainder;
  std::sort(intervals.begin(), intervals.end(),
    [] (Interval& a, Interval& b) {return a.start < b.start;}
  );
  Interval left = intervals[0];

  for (int i = 1; i < intervals.size(); i++) {
    if (left.end < intervals[i].start) {
      left = intervals[i];
    }

    else {
      bool leftEndBigger = left.end < intervals[i].end ? false : true;
      if (leftEndBigger) {
        remainder.push_back(left);
        left = intervals[i];
      }
      else {
        remainder.push_back(intervals[i]);
      }
    }
  }

  //do the same for remainder if it exists
  return remainder.size() > 0 ? 1 + minMeetingRooms(remainder) : 1;
}

