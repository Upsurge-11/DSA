#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(NULL) {}
  ListNode(int x) : val(x), next(NULL) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverseBetween(ListNode *head, int left, int right)
{
  ListNode *temp = new ListNode(0, head);
  ListNode *prev = temp;
  for (int i = 0; i < left - 1; i++)
    prev = prev->next;
  ListNode *curr = prev->next;
  for (int i = 0; i < right - left; i++)
  {
    ListNode *forw = curr->next;
    curr->next = forw->next;
    forw->next = prev->next;
    prev->next = forw;
  }
  return temp->next;
}

int main()
{

  return 0;
}