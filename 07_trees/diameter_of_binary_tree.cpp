#define NULL nullptr
#include <iostream>
#include <algorithm>

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode(): val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right): val(0), left(left), right(right) {} 
};

int dfs(TreeNode* root, int& res) {
  if (root == nullptr) {return 0;}
  
  int left = dfs(root -> left, res);
  int right = dfs(root -> right, res);

  res = std::max(res, left + right);
  return 1 + std::max(left, right);
}

int diameterOfBinaryTree(TreeNode* root) {
  int res = 0;
  dfs(root, res);
  return res;
}

int main() {
  TreeNode a0(0);
  TreeNode a1(1);
  TreeNode a2(2);
  TreeNode a3(3);
  TreeNode a4(4);
  TreeNode a5(5);
  TreeNode a6(6);

  a0.left = &a1;
  a0.right = &a2;
  a1.left = &a3;
  a1.right = &a4;
  a2.left = &a5;
  a2.right = &a6;

  std::cout << "Diameter of Tree: " << diameterOfBinaryTree(&a0) << std::endl;
}
