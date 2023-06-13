#include <bits/stdc++.h>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

bool hasCycle(ListNode *head) {
  if (head == NULL)
    return false;
  ListNode *slow = head;
  ListNode *fast = head->next;
  while (slow != fast) {
    if (fast == NULL || fast->next == NULL)
      return false;
    slow = slow->next;
    fast = fast->next->next;
  }
  return true;
}

int main() { return 0; }
