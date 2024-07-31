#include <vector>
#include <iostream>

using namespace std;

bool mergeTriplets(vector<vector<int>>& triplets, vector<int> target) {
  //the combination candidates must have all values
  //equal or smaller to the target value
  int checkCount = 0;

  for(const auto& t: triplets) {
    if (
      t[0] > target[0] ||
      t[1] > target[1] ||
      t[2] > target[2]
    ) {
      continue;
    }

    for (int i = 0; i < 3; i++) {
      if (t[i] == target[i]) {
        checkCount++;
      }
    }
  }

  //check if we have all 3 values
  return checkCount == 3;
}

int main() {
  vector<vector<int>> triplets = {{2, 5, 6}, {1, 4, 4}, {5, 7, 5}};
  vector<int> target = {5, 4, 6};
  
  mergeTriplets(triplets, target) ? 
    std::cout << "can merge" << std::endl :
    std::cout << "can't merge" << std::endl;

}