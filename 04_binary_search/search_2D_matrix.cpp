#include <iostream>
#include <vector>

bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
  int numRow = matrix.size();
  int numCol = matrix[0].size();

  //find row
  int l = 0;
  int r = numRow - 1;
  int m;
  int targetRow;

  while (l <= r) {
    m = l + (r - l) / 2;
    if (matrix[m][0] > target) {
      r = m - 1;
    } else if (matrix[m][numCol - 1] < target) {
      l = m + 1;
    } else {
      break;
    }
  } 

  if (!(l <= r)) {return false;}
  targetRow = m;

  l = 0;
  r = numCol - 1;

  while (l <= r) {
    m = l + (r - l) / 2;
    if (target == matrix[targetRow][m]) {
      return true;
    } else if (matrix[targetRow][m] < target) {
      l = m + 1;
    } else {
      r = m - 1;
    }
  }

  return false;
}

int main() {
  std::vector<std::vector<int>> matrix = {{1,2,4,8},{10,11,12,13},{14,20,30,40}};
  int target = 10;

  if (searchMatrix(matrix, target)) {
    std::cout << "true" << std::endl;
  }
  else {
    std::cout << "false" << std::endl;
  }


}