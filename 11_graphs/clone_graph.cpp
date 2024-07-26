#include <iostream>
#include <vector>
#include <set>
#include <deque>
#include <unordered_map>

class Node {
public:
  int val;
  std::vector<Node*> neighbors;

  Node() {
    val = 0;
    neighbors = std::vector<Node*>();
  }

  Node(int _val) {
    val = _val;
    neighbors = std::vector<Node*> ();
  }

  Node(int _val, std::vector<Node*> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

Node* cloneGraph(Node* node) {
  std::set<Node*> visited;
  std::deque<Node*> q;
  std::unordered_map<Node*, Node*> oldToNew;

  q.push_back(node);

  //init (no connections)
  //bfs
  while (!q.empty()) {
    Node* curr = q.front();
    visited.insert(curr);

    q.pop_front();
    oldToNew[curr] = new Node(curr->val);

    for (auto &n: curr -> neighbors) {
      if (visited.find(n) == visited.end()) {
        q.push_back(n);
      }
    }
  }

  //making connections
  for (auto &old: oldToNew) {
    for(Node* &oldNeighbor: old.first -> neighbors) {
      old.second -> neighbors.push_back(oldToNew[oldNeighbor]);
    }
  }

  return oldToNew[node];
}

int main() {

}
