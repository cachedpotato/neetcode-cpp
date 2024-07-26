#include <vector>
#include <set>
#include <iostream>
#include <tuple>
#include <string>

using namespace std;

void dfs(int i, int j, int n, vector<vector<char>>& board, string& word, set<tuple<int, int>>& visited, bool& res);
bool exist(vector<vector<char>>& board, string word);
bool dfs2(
  int i, int j, int n, int numRow, int numCol,
  vector<vector<char>>& board,
  string& word
);
bool exist2(vector<vector<char>>& board, string word);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main() {
  vector<vector<char>> board = {
    {'A','B','C','E'},
    {'S','F','C','S'},
    {'A','D','E','E'}
  };
  string word = "ABCCED";

  bool e = exist(board, word);
  std::cout << e << std::endl;
  bool ee = exist2(board, word);
  std::cout << ee << std::endl;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void dfs(int i, int j, int n, vector<vector<char>>& board, string& word, set<tuple <int, int>>& visited, bool& res) {
  int size = word.size();
  if (n == size - 1) {res = true; return;}
  int numRow = board.size();
  int numCol = board[0].size();

  tuple<int, int> oldCoord = make_tuple(i, j);
  visited.insert(oldCoord);
  vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

  for (const auto &d: directions) {
    int nr = i + d[0];
    int nc = j + d[1];
    tuple <int, int> newCoord = make_tuple(nr, nc);

    if (
      (0 <= nr && nr < numRow) &&
      (0 <= nc && nc < numCol) &&
      (visited.find(newCoord) == visited.end()) &&
      (board[nr][nc] == word[n + 1])
    ) {
      n++;
      dfs(nr, nc, n, board, word, visited, res);
    }

  }
}

bool exist(vector<vector<char>>& board, string word) {
  int numRow = board.size();
  int numCol = board[0].size();
  char start = word[0];
  set<tuple<int, int>> visited;
  bool res;

  for (int i = 0; i < numRow; i++) {
    for (int j = 0; j < numCol; j++) {
      if (board[i][j] == start) {
        dfs(i, j, 0, board, word, visited, res);
        if (res) {return true;}
        visited.clear();
      }
    }
  }

  return false;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool dfs2(
  int i, int j, int n, int numRow, int numCol,
  vector<vector<char>>& board,
  string& word 
) {
  if (
    i < 0 || i >= numRow || 
    j < 0 || j >= numCol || 
    board[i][j] != word[n]
  ) {
    return false;
  }

  if (n == word.size() - 1) {return true;}

  //instead of keeping a set to track visited cells
  //change the board itself
  board[i][j] == '#';
  
  if (
    dfs2(i + 1, j, n + 1, numRow, numCol, board, word) ||
    dfs2(i - 1, j, n + 1, numRow, numCol, board, word) ||
    dfs2(i, j + 1, n + 1, numRow, numCol, board, word) ||
    dfs2(i, j - 1, n + 1, numRow, numCol, board, word)
  ) {
    return true;
  }

  //if we couldn't find a match - revert the board
  //back to previous state
  board[i][j] = word[n];
  return false;
}

bool exist2(vector<vector<char>>& board, string word) {
  int numRow = board.size();
  int numCol = board[0].size();
  int n = 0; //index

  for (int i = 0; i < numRow; i++) {
    for (int j = 0; j < numCol; j++) {
      if (board[i][j] == word[0]) {
        if (dfs2(i, j, n, numRow, numCol, board, word)) {return true;}
      }
    }
  }
  return false;
}
