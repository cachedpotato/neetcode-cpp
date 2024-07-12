#define NULL nullptr
#include <iostream>
#include <algorithm>
#include <stack>

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode(): val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right): val(0), left(left), right(right) {} 
};

int kthSmallest(TreeNode* root, int k) {
  if (!root) {return -1;}

  std::stack<TreeNode*> nodeStack;
  TreeNode* curr = root;

  while (curr != nullptr || !nodeStack.empty()) {
    while (curr != nullptr) {
      nodeStack.push(curr);
      curr = curr -> left;
    }

    curr = nodeStack.top();
    nodeStack.pop();

    k--;
    if (k == 0) {return curr -> val;}

    curr = curr -> right;
  }
  return -1;
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

  int k = 3;
  int res = kthSmallest(&a0, k);
  std::cout << res << std::endl;
}