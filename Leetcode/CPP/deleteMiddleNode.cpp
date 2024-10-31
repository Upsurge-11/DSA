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

// ListNode *deleteMiddle(ListNode *head)
// {
//   ListNode *temp = head;
//   int count = 1;
//   while (temp->next != NULL)
//   {
//     count++;
//     temp = temp->next;
//   }
//   count /= 2;
//   temp = head;
//   while (count--)
//   {
//     temp = temp->next;
//   }
//   temp->val = temp->next->val;
//   temp->next = temp->next->next;
//   return head;
// }

ListNode *deleteMiddle(ListNode *head)
{
  if (head == NULL || head->next == NULL)
    return NULL;
  ListNode *slow = head;
  ListNode *fast = head;
  ListNode *prev = NULL;
  while (fast != NULL && fast->next != NULL)
  {
    prev = slow;
    slow = slow->next;
    fast = fast->next->next;
  }
  prev->next = slow->next;
  return head;
}

int main()
{

  return 0;
}