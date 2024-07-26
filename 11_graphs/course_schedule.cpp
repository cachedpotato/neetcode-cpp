#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;

bool dfs(unordered_map<int, vector<int>>& preMap, unordered_set<int>& cycle, unordered_set<int>& visited, int curr) {
  if (cycle.find(curr) != cycle.end()) {
    return false;
  }

  if (visited.count(curr)) {
    return true;
  };

  cycle.insert(curr);
  for (const auto &pre: preMap[curr]) {
    if (!dfs(preMap, cycle, visited, pre)) {return false;}
  }
  cycle.erase(curr);
  visited.insert(curr);
  return true;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
  //topological sort
  unordered_map<int, vector<int>> preMap;
  unordered_set<int> cycle;
  unordered_set<int> visited;

  for (const auto &p: prerequisites) {
    preMap[p[0]].push_back(p[1]);
  }

  for (const auto &p: preMap) {
    if (!dfs(preMap, cycle, visited, p.first)) {
      return false;
    }
  }
  
  return true;
}

int main() {
  int numCourses = 2;
  vector<vector<int>> prerequisites = {{0, 1}};

  canFinish(numCourses, prerequisites) ? cout << "yes" << endl : cout << "No" << endl;
}