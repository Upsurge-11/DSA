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

vector<ListNode *> splitListToParts(ListNode *head, int k)
{
  vector<ListNode *> ans(k, nullptr);
  int len = 0;

  ListNode *temp = head;
  while (temp)
  {
    len++;
    temp = temp->next;
  }

  int size = len / k;
  int rem = len % k;

  ListNode *node = head;
  ListNode *prev = nullptr;

  for (int i = 0; node && i < k; i++)
  {
    ans[i] = node;
    for (int j = 0; j < size; j++)
    {
      prev = node;
      node = node->next;
    }
    if (rem > 0)
    {
      prev = node;
      node = node->next;
      rem--;
    }
    prev->next = nullptr;
  }
  return ans;
}

int main()
{

  return 0;
}