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

bool isSameTree(TreeNode* p, TreeNode* q) {
  if (!p && !q) {return true;}
  if ((!p && q) || (p && !q)) {return false;}
  if (p -> val != q -> val) {return false;}

  return isSameTree(p -> left, q -> left) && isSameTree(p -> right, q -> right);
}




int main() {
  TreeNode a0(0);
  TreeNode a1(1);
  TreeNode a2(2);
  a0.right = &a2;
  a0.left = &a1;

  TreeNode b0(0);
  TreeNode b1(1);
  TreeNode b2(2);
  b0.left = &b1;
  b0.right = &b2;

  if (isSameTree(&a0, &b0)) {
    std::cout << "Same Tree" << std::endl;
  } else {
    std::cout << "Different Tree" << std::endl;
  }

}
