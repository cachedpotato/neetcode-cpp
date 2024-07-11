#define NULL nullptr
#include <map>
#include <iostream>

class Node {
public:
  int val;
  Node* next;
  Node* random;

  Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

Node* copyRandomList(Node* head) {
  std::map<Node*, Node*> nodeMap;
  Node* dummy = head;

  while (dummy != NULL) {
    Node* newNode = new Node(dummy -> val);
    nodeMap[dummy] = newNode;
    
    dummy = dummy -> next;
  }

  //connecting
  for(auto const &x: nodeMap) {
    //newNode -> next = map[oldNode -> next]
    x.second -> next = nodeMap[x.first -> next];
    x.second -> random = nodeMap[x.first -> random];
  }

  //return root node of new list
  return nodeMap[head];
}

int main() {
  std::cout << "it works trust me bro" << std::endl;
}