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

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
  ListNode root(0);
  ListNode* curr = &root;

  while (list1 != NULL && list2 != NULL) {
    if (list1 -> val < list2 -> val) {
      curr -> next = list1;
      list1 = list1 -> next;
    } else {
      curr -> next = list2;
      list2 = list2 -> next;
    }
    curr = curr -> next;
  }

  if (list1 == NULL) {
    curr -> next = list2;
  } else {
    curr -> next = list1;
  }

  return root.next;
}

int main() {
  ListNode l11(1);
  ListNode l12(2);
  ListNode l13(4);
  l11.next = &l12;
  l12.next = &l13;

  ListNode l21(1);
  ListNode l22(3);
  ListNode l23(5);
  l21.next = &l22;
  l22.next = &l23;

  ListNode* res = mergeTwoLists(&l11, &l21);

  while (res != NULL) {
    std::cout << res -> val << std::endl;
    res = res -> next;
  }
}