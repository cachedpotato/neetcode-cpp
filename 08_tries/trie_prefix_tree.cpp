#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

class TreeNode {
public:
  char val;
  std::vector<TreeNode*> neighbors;
  bool end;

  TreeNode() {
    val = '0';
    std::vector<TreeNode*> n(27, nullptr);
    this -> neighbors = n;
    end = false;
  }

  TreeNode(char _val) {
    val = _val;
    std::vector<TreeNode*> n(27, nullptr);
    this -> neighbors = n;
    end = false;
  }
};

class PrefixTree {
private:
  TreeNode* root;

public:
  PrefixTree() {
    this->root = new TreeNode('0');
  }

  void insert(std::string word) {
    TreeNode* curr = root;
    for (const char& c: word) {
      if (curr -> neighbors[c - 'a'] == nullptr) {
        curr ->neighbors[c - 'a'] = new TreeNode(c);
      }

      curr = curr -> neighbors[c - 'a'];
    }
    curr -> end = true;
  }

  bool search(std::string word) {
    TreeNode* curr = root;
    for (const char &c: word) {
      if (curr -> neighbors[c - 'a'] == nullptr) {
        return false;
      }
      curr = curr -> neighbors[c - 'a'];
    }
    return curr -> end;
  }

  bool startsWith (std::string prefix) {
    TreeNode* curr = root;
    for (const char &c: prefix) {
      if (curr -> neighbors[c - 'a'] == nullptr) {
        return false;
      }
      curr = curr -> neighbors[c - 'a'];
    }
    return true;
  }
};

int main() {

PrefixTree* prefixTree = new PrefixTree();
  prefixTree -> insert("dog");
  std::cout << prefixTree -> search("dog") << std::endl;    // return true
  std::cout << prefixTree -> search("do") << std::endl;     // return false
  std::cout << prefixTree -> startsWith("do") << std::endl; // return true
  prefixTree -> insert("do");
  std::cout << prefixTree -> search("do") << std::endl;     // return true
}