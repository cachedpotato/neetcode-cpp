#define NULL nullptr
#include <iostream>
#include <stack>

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode(): val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right): val(0), left(left), right(right) {} 
};

TreeNode* invertTree(TreeNode* root) {
  if (root == NULL) {return NULL;}

  TreeNode* newNode = new TreeNode(root -> val);
  newNode -> left = invertTree(root -> right);
  newNode -> right = invertTree(root -> left);

  return newNode;
}

void dfs(TreeNode* root) {
  if (root == NULL) {return;}

  dfs(root -> left);

  std::cout << root -> val << " ";

  dfs(root -> right);

  return;
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

  dfs(&a0);
  std::cout << std::endl;
  TreeNode* r = invertTree(&a0);
  dfs(r);
  std::cout << std::endl;
}
