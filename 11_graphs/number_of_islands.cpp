#include <iostream>
#include <vector>
#include <set>
#include <tuple>

using namespace std;

void bfs(
  vector<vector<char>>& grid, 
  set<tuple<int, int>>& visited,
  int numRow,
  int numCol,
  int i,
  int j
);

int numIslands(vector<vector<char>>& grid) {
  set<tuple<int, int>> visited;
  int numRow = grid.size();
  int numCol = grid[0].size();
  int numIslands = 0;

  for (int i = 0; i < numRow; i++) {
    for (int j = 0; j < numCol; j++) {
      tuple<int, int> currentCoord = {i, j};
      if (grid[i][j] == '1' && visited.find((currentCoord)) == visited.end()) {
        bfs(grid, visited, numRow, numCol, i, j);
        numIslands++;
      }
    }
  }

  return numIslands;
}

int main() {
  vector<vector<char>> grid = {
    {'1','1','0','0','1'},
    {'1','1','0','0','1'},
    {'0','0','1','0','0'},
    {'0','0','0','1','1'}
  };

  cout << numIslands(grid) << endl;
}

/////////////////////////////////////////
void bfs(
  vector<vector<char>>& grid, 
  set<tuple<int, int>>& visited,
  int numRow,
  int numCol,
  int i,
  int j
) {

  if (i < 0 || i >= numRow ||
      j < 0 || j >= numCol ||
      grid[i][j] == '0' ||
      visited.find({i, j}) != visited.end()) {
        return;
  }

  tuple<int, int> curr = {i, j};
  visited.insert(curr);

  bfs(grid, visited, numRow, numCol,
      i + 1, j);
  bfs(grid, visited, numRow, numCol,
      i - 1, j);
  bfs(grid, visited, numRow, numCol,
      i, j + 1);
  bfs(grid, visited, numRow, numCol,
      i, j - 1);
}