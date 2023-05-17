#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int pairSum(ListNode *head)
{
  ListNode *slow = head;
  ListNode *fast = head;
  int ans = 0;
  while (fast && fast->next)
  {
    slow = slow->next;
    fast = fast->next->next;
  }
  ListNode *nextNode, *prev = NULL;
  while (slow)
  {
    nextNode = slow->next;
    slow->next = prev;
    prev = slow;
    slow = nextNode;
  }
  while (prev)
  {
    ans = max(ans, head->val + prev->val);
    prev = prev->next;
    head = head->next;
  }
  return ans;
}

int main()
{

  return 0;
}