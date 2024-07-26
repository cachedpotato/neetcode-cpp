#include <vector>
#include <iostream>
#include <queue>
#include <math.h>
using namespace std;


float d(vector<int>& p) {
  return sqrt(pow(p[0], 2) + pow(p[1], 2));
}

class Compare {
public:
  bool operator() (vector<int> below, vector<int> above) {
    if (d(above) < d(below)) {
      return false;
    }
    return true;
  }
};

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
  priority_queue<vector<int>, vector<vector<int>>, Compare> coordHeap;
  for (const auto &p: points) {
    coordHeap.push(p);
    if (coordHeap.size() > k) {
      coordHeap.pop();
    }
  }

  vector<vector<int>> out;
  while (!coordHeap.empty()) {
    out.push_back(coordHeap.top());
    coordHeap.pop();
  }

  return out;
}

int main() {
  vector<vector<int>> points = {{0, 2}, {2, 0}, {2, 2}, {1, 1}};
  vector<vector<int>> out = kClosest(points, 2);

  for (const auto &v: out) {
    std::cout << v[0] << " " << v[1] << std::endl;
  }
}