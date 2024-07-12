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

bool hasCycle(ListNode* head) {
  ListNode* slow = head;
  ListNode* fast = head;

  while (fast != NULL && fast -> next != NULL) {
    slow = slow -> next;
    fast = fast -> next -> next;

    if (slow == fast) {
      return true;
    }
  }

  return false;
}

int main() {
  ListNode one(1);
  ListNode two(1);
  ListNode three(1);
  ListNode four(1);

  one.next = &two;
  two.next = &three;
  three.next = &four;
  four.next = &two;

  if (hasCycle(&one)) {
    std::cout << "has loop" << std::endl;
  } else {
    std::cout << "no loop" << std::endl;
  }
}