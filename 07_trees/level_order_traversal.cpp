#define NULL nullptr
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode(): val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right): val(0), left(left), right(right) {} 
};

std::vector<std::vector<int>> levelOrder(TreeNode* root) {
  if (!root) {return {};}

  std::deque<TreeNode*> q;
  q.push_back(root);
  std::vector<std::vector<int>> out;
  while(!q.empty()) {
    std::vector<int> level;
    for (int _i = 0, len = q.size(); _i < len; _i++) {
      TreeNode* curr = q.front();
      q.pop_front();
      level.push_back(curr -> val);

      if (curr -> left) {
        q.push_back(curr -> left);
      }
      if (curr -> right) {
        q.push_back(curr -> right);
      }
    }
    out.push_back(level);
  }
  return out;
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

  for (auto &l: levelOrder(&a0)) {
    for(auto &e: l) {
      std::cout << e;
    }
    std::cout << std::endl;
  }
}