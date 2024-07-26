#include <iostream>
#include <vector>
#include <math.h>
#include <queue>

using namespace std;

int orangesRotting(vector<vector<int>>& grid);

int main() {
  vector<vector<int>> grid = {
    {1, 1, 0},
    {0, 1, 1},
    {0, 1, 2}
  };

  cout << orangesRotting(grid) << endl;
}
///////////////////////////////////////////////////////

//simulatneous simulation
//go for BFS not DFS
//increase time only after every rotten orange at given "layer" is computed

int orangesRotting(vector<vector<int>>& grid) {
  queue<pair<int, int>> q;
  int rows = grid.size();
  int cols = grid[0].size();
  int fresh = 0;
  int time = 0;

  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      if (grid[r][c] == 1) {
        fresh++;
      }
      else if (grid[r][c] == 2) {
        q.push({r, c});
      }
    }
  }

  vector<pair<int, int>> directions = {
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1}
  };

  while (fresh > 0 && !q.empty()) {
    int length = q.size();
    for (int _i = 0; _i < length; _i++) {
      auto curr = q.front();
      q.pop();
      int r = curr.first;
      int c = curr.second;

      for (const auto &d: directions) {
        int nr = r + d.first;
        int nc = c + d.second;
        if (
          nr >= 0 && nr < rows &&
          nc >= 0 && nc < cols &&
          grid[nr][nc] == 1
        ) {
          grid[nr][nc] = 2;
          q.push({nr, nc});
          fresh--;
        }
      }
    }
    time++;
  }

  return fresh == 0 ? time : -1;
}
