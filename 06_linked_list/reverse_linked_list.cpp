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

ListNode* reverseList(ListNode* head) {
  if (head == NULL || head -> next == NULL) {
    return head;
  }

  ListNode* prev = NULL;
  ListNode* curr = head;

  while (curr != NULL) {
    ListNode* temp = curr -> next;
    curr -> next = prev;
    prev = curr;
    curr = temp;
  }

  return prev;
}

int main() {
  ListNode head(0);
  ListNode one(1);
  ListNode two(2);
  ListNode three(3);
  head.next = &one;
  one.next = &two;
  two.next = &three;

  ListNode* rev = reverseList(&head);
  ListNode* curr = rev;

  while (curr != NULL) {
    std::cout << curr -> val << std::endl;
    curr = curr->next;
  }
}