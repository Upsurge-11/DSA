#include <bits/stdc++.h>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
  ListNode *head = new ListNode();
  ListNode *temp = head;
  while (list1 && list2) {
    if (list1->val < list2->val) {
      temp->next = list1;
      list1 = list1->next;
    } else {
      temp->next = list2;
      list2 = list2->next;
    }
    temp = temp->next;
  }
  temp->next = list1 ? list1 : list2;
  return head->next;
}

int main() { return 0; }
