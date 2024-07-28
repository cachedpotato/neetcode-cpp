#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;


bool validTree(int n, vector<vector<int>>& edges);
bool dfs(unordered_map<int, vector<int>>& connections, unordered_set<int>& visited, unordered_set<int>& cycle, int curr, int prev);

int main() {
  int n = 5;
  vector<vector<int>> edges = {{0, 1}, {0,2}, {0,3}, {1,4}};

  validTree(n, edges) ? cout << "valid" << endl : cout << "not valid" << endl;
}

//////////////////////////////////////////////////////////////////////////////////////////

bool validTree(int n, vector<vector<int>>& edges) {
  unordered_map<int, vector<int>> connections;
  unordered_set<int> visited;
  unordered_set<int> cycle;

  //bidirectional
  for (const auto &e: edges) {
    connections[e[0]].push_back(e[1]);
    connections[e[1]].push_back(e[0]);
  }
  bool out = dfs(connections, visited, cycle, 0, -1);

  return visited.size() != n ? false : out;
}

bool dfs(unordered_map<int, vector<int>>& connections, unordered_set<int>& visited, unordered_set<int>& cycle,int curr, int prev) {
  if (visited.count(curr)) {
    return false;
  }

  visited.insert(curr);
  for (const auto &n: connections[curr]) {
    if (n == prev) {continue;}
    if (!dfs(connections, visited, cycle, n, curr)) {
      return false;
    }
  }
  return true;
}