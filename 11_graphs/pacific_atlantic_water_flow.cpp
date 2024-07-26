#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights);
void bfs(vector<vector<int>>& heights, set<pair<int, int>>& visited, vector<vector<int>>& out, int& rows, int& cols, int r, int c);

int main() {
  vector<vector<int>> heights = {
    {4,2,7,3,4},
    {7,4,6,4,7},
    {6,3,5,3,6},
  };

  cout << "[";
  for (const auto& c: pacificAtlantic(heights)) {
    cout << "[" << c[0] << "," <<c[1] << "],";
  }
  cout << "]" << endl;
}

///////////////////////////////////////////////////////////////////////////////////////////
vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
  //pacific: rows < 0 or cols < 0
  //atlantic: rows >= numRows or cols >= numCols
  vector<vector<int>> out;
  set<pair<int, int>> visited;
  int rows = heights.size();
  int cols = heights[0].size();

  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      bfs(heights, visited, out, rows, cols, r, c);
      visited.clear();
    }
  }

  return out;
}

void bfs(vector<vector<int>>& heights, set<pair<int, int>>& visited, vector<vector<int>>& out, int& rows, int& cols, int r, int c) {
  bool pacific = false;
  bool atlantic = false;
  queue<pair<int, int>> q;

  q.push({r, c});
  visited.insert({r, c});

  vector<pair<int, int>> directions = {{1, 0},{-1, 0},{0, 1},{0, -1}};
  while (!q.empty()) {
    auto curr = q.front();
    q.pop();
    int cr =  curr.first;
    int cc = curr.second;
    visited.insert({cr, cc});

    for (const auto &d: directions) {
      int nr = cr + d.first;
      int nc = cc + d.second;
      if (nr < 0 || nc < 0 ) {
        pacific = true;
      } 
      else if (nr >= rows || nc >= cols) {
        atlantic = true;
      }
      else if (
        nr >= 0 && nr < rows &&
        nc >= 0 && nc < cols &&
        visited.find({nr, nc}) == visited.end() &&
        heights[nr][nc] <= heights[cr][cc]
      ) {
        q.push({nr, nc});
      }
    }

    if (pacific && atlantic) {
      out.push_back({r, c});
      return;
    }
  }
}


