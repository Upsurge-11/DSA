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

ListNode *reverseList(ListNode *head)
{
  ListNode *prev = NULL;
  while (head)
  {
    ListNode *nxt = head->next;
    head->next = prev;
    prev = head;
    head = nxt;
  }
  return prev;
}

ListNode *func(ListNode *l1, ListNode *l2)
{
  ListNode *head = new ListNode(0);
  ListNode *curr = head;
  int carry = 0;
  while (l1 || l2 || carry)
  {
    int sum = 0;
    if (l1)
    {
      sum += l1->val;
      l1 = l1->next;
    }
    if (l2)
    {
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

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
  l1 = reverseList(l1);
  l2 = reverseList(l2);
  ListNode *ans = func(l1, l2);
  return reverseList(ans);
}

int main()
{

  return 0;
}