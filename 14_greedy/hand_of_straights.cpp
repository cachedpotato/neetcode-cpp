#include <vector>
#include <iostream>
#include <map>

bool isNStraightHand(std::vector<int> hand, int groupSize) {
  std::map<int, int> count;
  for (int n: hand) {
    count[n] += 1;
  }

  //biggest number first
  while (!count.empty()) {
    int maxNum = count.rbegin() -> first;
    int maxCount = count.rbegin() -> second;

    for (int i = maxNum - groupSize + 1; i < maxNum + 1; i++) {
      if (count.find(i) == count.end()) {return false;}
      count[i] -= maxCount;
      if (count[i] > 0) {continue;}
      else if (count[i] == 0) {count.erase(i);}
      else {return false;}
    }
  }
  //should be clean
  return count.empty();
}

int main() {
  std::vector<int> hand = {1, 2, 4, 2, 3, 5, 3, 4};
  int groupSize = 4;

  isNStraightHand(hand, groupSize) ? std::cout << "is straight hand" << std::endl : std::cout << "not straight hand" << std::endl;
}