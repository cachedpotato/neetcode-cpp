#define NULL nullptr
#include <iostream>

struct ListNode {
  int val;
  ListNode* next;

  //constructor overloading
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x): val(x), next(nullptr) {}
  ListNode(ListNode* next) : val(0), next(next) {}
  ListNode(int x, ListNode* next): val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
  ListNode dummy(0);
  dummy.next = head;
  ListNode* l = &dummy;
  ListNode* r = head;

  //moving r down the list
  //distance between l and r: n + 1
  for(int i = 0; i < n; i++) {
    r = r -> next;
  }

  //l -> ListNode[end - n + 1]... -> ListNode[end] -> r
  while (r != NULL) {
    l = l -> next;
    r = r -> next;
  }

  //l at n+1th position from end
  ListNode* temp = l -> next;
  l -> next = l -> next -> next;

  return dummy.next;
}

int main() {
  ListNode root(0);
  ListNode one(1);
  ListNode two(2);
  ListNode three(3);

  root.next = &one;
  one.next = &two;
  two.next = &three;

  int n = 2;

  ListNode* res = removeNthFromEnd(&root, n);

  while (res != NULL) {
    std::cout << res -> val << std::endl;
    res = res -> next;
  }
}