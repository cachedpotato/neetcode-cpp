#define NULL nullptr
#include <iostream>
#include <stack>
#include <algorithm>

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode(): val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right): val(0), left(left), right(right) {} 
};

int maxDepth(TreeNode* root) {
  if (root == NULL) {return 0;}

  return 1 + std::max(maxDepth(root -> left), maxDepth(root -> right));
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

  std::cout << "Depth of tree: " << maxDepth(&a0) << std::endl;

}
