#include <bits/stdc++.h>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(NULL) {}
  ListNode(int x) : val(x), next(NULL) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
  ListNode *head = new ListNode(0);
  ListNode *curr = head;
  int carry = 0;
  while (l1 || l2 || carry) {
    int sum = 0;
    if (l1) {
      sum += l1->val;
      l1 = l1->next;
    }
    if (l2) {
      sum += l2->val;
      l2 = l2->next;
    }
    sum += carry;
    carry = sum / 10;
    curr->next = new ListNode(sum % 10);
    curr = curr->next;
  }
  return head->next;
}

int main() { return 0; }
