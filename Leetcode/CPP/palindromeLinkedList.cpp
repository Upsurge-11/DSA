#include <bits/stdc++.h>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(NULL) {}
  ListNode(int x) : val(x), next(NULL) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverseList(ListNode *head) {
  ListNode *pre = NULL, *cur = head, *nex = NULL;
  while (cur != NULL) {
    nex = cur->next;
    cur->next = pre;
    pre = cur;
    cur = nex;
  }
  return pre;
}

bool isPalindrome(ListNode *head) {
  if (head == NULL || head->next == NULL)
    return true;
  ListNode *slow = head, *fast = head;
  while (fast->next != NULL && fast->next->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;
  }
  slow->next = reverseList(slow->next);
  slow = slow->next;
  while (slow != NULL) {
    if (head->val != slow->val)
      return false;
    head = head->next;
    slow = slow->next;
  }
  return true;
}

int main() { return 0; }
