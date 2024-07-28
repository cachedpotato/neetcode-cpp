#include <vector>
#include <string>
#include <iostream>

using namespace std;

class TrieNode
{
public:
  vector<TrieNode*> children;
  bool end;

  TrieNode(): children(26, nullptr), end(false) {}
};

class WordDictionary {
private:
  TrieNode* root;
  bool dfs(string word, int currIdx, TrieNode* curr) {
    for (int i = currIdx; i < word.size(); i++) {
      char c = word[i];
      if (c == '.') {
        for (TrieNode* n: curr -> children) {
          if (n != nullptr && dfs(word, i + 1, n)) {
            return true;
          }
        }
        return false;
      } else {
        int idx = word[i] - 'a';
        if (curr -> children[idx] == nullptr) {
          return false;
        }
        curr = curr -> children[idx];
      }
    }
    return curr -> end;
  }
public:
  WordDictionary(): root(new TrieNode()) {}

  void addWord(string word) {
    TrieNode* curr = root;
    for (char c: word) {
      int idx = c - 'a';
      if (curr -> children[idx] == nullptr) {
        curr -> children[idx] = new TrieNode();
      }
      curr = curr -> children[idx];
    }
    curr -> end = true;
  }

  bool search(string word) {
    return dfs(word, 0, root);
  }
};

int main() {
  WordDictionary* wordDictionary = new WordDictionary();
  wordDictionary -> addWord("day");
  wordDictionary -> addWord("bay");
  wordDictionary -> addWord("may");
  std::cout << wordDictionary -> search("say") << std::endl; // return false
  std::cout << wordDictionary -> search("day") << std::endl; // return true
  std::cout << wordDictionary -> search(".ay") << std::endl; // return true
  std::cout << wordDictionary -> search("b..") << std::endl; // return true
}