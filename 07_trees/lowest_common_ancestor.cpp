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

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  if (p -> val < root -> val && q -> val < root -> val) {
    return lowestCommonAncestor(root -> left, p, q);
  } else if (p -> val > root -> val && q -> val > root -> val) {
    return lowestCommonAncestor(root -> right, p, q);
  } else {
    return root;
  }
}

TreeNode* lowestCommonAncestorImproved(TreeNode* root, TreeNode* p, TreeNode* q) {
  while (true) {
    if (root -> val < p -> val && root -> val < q -> val) {
      root = root -> right;
    } else if (root -> val > p -> val && root -> val > q ->  val) {
      root = root -> left;
    } else {
      return root;
    }
  }
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

  std::cout << lowestCommonAncestor(&a0, &a3, &a4) -> val << std::endl;
  std::cout << lowestCommonAncestorImproved(&a0, &a3, &a4) -> val << std::endl;

}