#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites);
bool dfs(unordered_map<int, vector<int>>& preMap, unordered_set<int>& visited, unordered_set<int>& cycle, vector<int>& out, int curr);

int main() {
  int numCourses = 4;
  vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
  vector<int> res = findOrder(numCourses, prerequisites);

  cout << "COURSE ORDER: ";
  for (int &c: res) {
    cout << c << ' ';
  }
  cout << endl;
}

//////////////////////////////////////////////////////////////////////////////

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
  unordered_map<int, vector<int>> preMap;
  unordered_set<int> visited;
  unordered_set<int> cycle;
  vector<int> out;

  for (const auto &p: prerequisites) {
    preMap[p[0]].push_back(p[1]);
  }

  for (int course = 0; course < numCourses; course++) {
    if (!dfs(preMap, visited, cycle, out, course)) {
      return {};
    }
  }

  return out;
}


bool dfs(unordered_map<int, vector<int>>& preMap, unordered_set<int>& visited, unordered_set<int>& cycle, vector<int>& out, int curr) {
  if (cycle.find(curr) != cycle.end()) {
    return false;
  } 

  if (visited.find(curr) != visited.end()) {
    return true;
  }

  cycle.insert(curr);
  for (const auto &pre: preMap[curr]) {
    if (!dfs(preMap, visited, cycle, out, pre)) {
      return false;
    }
  }
  cycle.erase(curr);
  visited.insert(curr);
  out.push_back(curr);
  return true; 
}