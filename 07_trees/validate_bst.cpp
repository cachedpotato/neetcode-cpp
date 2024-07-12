#define NULL nullptr
#include <iostream>
#include <algorithm>
#include <limits>

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode(): val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right): val(0), left(left), right(right) {} 
};

bool dfs(TreeNode* node, int leftBoundary, int rightBoundary) {
  if (!node) {return true;}

  if (node -> val <= leftBoundary || node -> val >= rightBoundary) {
    return false;
  }

  return dfs(node -> left, leftBoundary, node -> val) && dfs(node -> right, node -> val, rightBoundary);
}

bool isValidBST(TreeNode* root) {
  return dfs(root, INT16_MIN, INT16_MAX);
}

int main() {
  TreeNode a0(5);
  TreeNode a1(3);
  TreeNode a2(8);
  TreeNode a3(1);
  TreeNode a4(4);
  TreeNode a5(7);
  TreeNode a6(9);

  a0.left = &a1;
  a0.right = &a2;
  a1.left = &a3;
  a1.right = &a4;
  a2.left = &a5;
  a2.right = &a6;

  if (isValidBST(&a0)) {
    std::cout << "is valid BST" << std::endl;
  } else {
    std::cout << "is not valid BST" << std::endl;
  }
}