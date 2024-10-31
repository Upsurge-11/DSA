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

ListNode *partition(ListNode *head, int x)
{
  ListNode *less = new ListNode(0);
  ListNode *greater = new ListNode(0);
  ListNode *lessHead = less;
  ListNode *greaterHead = greater;
  while (head)
  {
    if (head->val < x)
    {
      less->next = head;
      less = less->next;
    }
    else
    {
      greater->next = head;
      greater = greater->next;
    }
    head = head->next;
  }
  greater->next = nullptr;
  less->next = greaterHead->next;
  return lessHead->next;
}

int main()
{

  return 0;
}