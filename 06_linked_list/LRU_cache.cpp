#include <map>
#include <iostream>
#include <algorithm>
#include <math.h>

struct DListNode {
  int key;
  int value;
  DListNode* left;
  DListNode* right;

  DListNode(): key(0), value(0), left(nullptr), right(nullptr) {}
  DListNode(int key, int value): key(key), value(value), left(nullptr), right(nullptr) {}
};

class LRUCache {
private:
  int cap;
  DListNode* left;
  DListNode* right;
  std::map<int, DListNode*> cacheMap;

  //helper functions
  void insertToRight(DListNode* newNode) {
    DListNode* prev = right -> left;
    prev -> right = newNode;
    right -> left = newNode;
    newNode -> left = prev;
    newNode -> right = right;
  }

  void remove(DListNode* Node) {
    DListNode* prev = Node -> left;
    DListNode* next = Node -> right;

    prev -> right = next;
    next -> left = prev;

    delete Node;
    Node = nullptr;
  }

public:
  LRUCache(int capacity) {
    cap = capacity;
    left = new DListNode(0, 0);
    right = new DListNode(0, 0);
    left -> right = right;
    right -> left = left;
  }

  int get(int key) {
    if (cacheMap.find(key) == cacheMap.end()) {
      return -1;
    }

    DListNode* accessedNode = cacheMap[key];
    int nk = accessedNode -> key;
    int nv = accessedNode -> value;
    DListNode* newNode = new DListNode(nk, nv);

    cacheMap[key] = newNode;
    remove(accessedNode);
    insertToRight(newNode);

    return cacheMap[key] -> value;
  }

  void put(int key, int value) {
    if (cacheMap.find(key) != cacheMap.end()) {
      remove(cacheMap[key]);
    }

    DListNode* newNode = new DListNode(key, value);
    cacheMap[key] = newNode;
    insertToRight(newNode);

    if (cacheMap.size() > cap) {
      int k = left -> right -> key;
      DListNode* lru = left -> right;
      remove(lru);
      cacheMap.erase(k);
    }
  }
};

int main() {
  LRUCache lRUCache(2);
  lRUCache.put(1, 10);  // cache: {1=10}
  int a = lRUCache.get(1);      // return 10
  std::cout << a << std::endl;
  lRUCache.put(2, 20);  // cache: {1=10, 2=20}
  lRUCache.put(3, 30);  // cache: {2=20, 3=30}, key=1 was evicted
  int b = lRUCache.get(2);      // returns 20 
  std::cout << b << std::endl;
  int c = lRUCache.get(1);      // return -1 (not found)
  std::cout << c << std::endl;
}