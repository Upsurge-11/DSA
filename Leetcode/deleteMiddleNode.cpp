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

ListNode *deleteMiddle(ListNode *head)
{
  ListNode *temp = head;
  int count = 0;
  while (temp->next != NULL)
  {
    count++;
    temp = temp->next;
  }
}

int main()
{

  return 0;
}