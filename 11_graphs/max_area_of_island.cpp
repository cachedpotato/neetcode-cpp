#include <iostream>
#include <vector>
#include <set>
#include <tuple>
#include <math.h>

using namespace std;

void bfs (
  vector<vector<int>>& grid, set<tuple<int, int>>& visited,
  int rows, int cols,
  int i, int j
);

int maxAreaOfIsland(vector<vector<int>>& grid);


int main() {
  vector<vector<int>> grid2 ={
    {0,0,1,0,0,0,0,1,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,1,1,0,0,0},
    {0,1,1,0,1,0,0,0,0,0,0,0,0},
    {0,1,0,0,1,1,0,0,1,0,1,0,0},
    {0,1,0,0,1,1,0,0,1,1,1,0,0},
    {0,0,0,0,0,0,0,0,0,0,1,0,0},
    {0,0,0,0,0,0,0,1,1,1,0,0,0},
    {0,0,0,0,0,0,0,1,1,0,0,0,0}
  };

  int res = maxAreaOfIsland(grid2);
  cout << res << endl;
}

/////////////////////////////////////////////////////////////////////////////////////
void bfs (
  vector<vector<int>>& grid, set<tuple<int, int>>& visited,
  int rows, int cols,
  int i, int j
) {

  if (i < 0 || i >= rows ||
      j < 0 || j >= cols ||
      grid[i][j] == 0 ||
      visited.find({i, j}) != visited.end()) {
        return;
  }

  visited.insert({i, j});

  bfs(grid, visited, rows, cols,
  i + 1, j);
  bfs(grid, visited, rows, cols,
  i - 1, j);
  bfs(grid, visited, rows, cols,
  i, j + 1);
  bfs(grid, visited, rows, cols,
  i, j - 1);

}

int bfs2 (
  //by returning the area of the island we don't need to do
  //extra steps of checking visited size in main function
  //Island can have "flanks" where there are areas both left/right or top/bottom
  //to get accurate area, add all four sides
  //return 0 if invalid 1 if good
  vector<vector<int>>& grid, set<tuple<int, int>>& visited,
  int rows, int cols,
  int i, int j
) {

  if (i < 0 || i >= rows ||
      j < 0 || j >= cols ||
      grid[i][j] == 0 ||
      visited.find({i, j}) != visited.end()) {
    return 0;
  }

  visited.insert({i, j});

  return ( 
    1 + //current
    bfs2(grid, visited, rows, cols, i + 1, j) +
    bfs2(grid, visited, rows, cols, i - 1, j) +
    bfs2(grid, visited, rows, cols, i, j + 1) +
    bfs2(grid, visited, rows, cols, i, j - 1)
  );
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
  int rows = grid.size();
  int cols = grid[0].size();
  set<tuple<int, int>> visited;
  int maxArea = 0;

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (grid[i][j] == 1 && visited.find({i, j}) == visited.end()) {
        maxArea = max(maxArea, bfs2(grid, visited, rows, cols, i, j));
      }
    }
  }

  return maxArea;

}

