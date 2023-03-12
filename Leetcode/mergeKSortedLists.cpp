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

ListNode *mergeKLists(vector<ListNode *> &lists)
{
  priority_queue<pair<int, ListNode *>, vector<pair<int, ListNode *>>, greater<pair<int, ListNode *>>> minHeap;
  for (int i = 0; i < lists.size(); i++)
  {
    if (lists[i] != NULL)
      minHeap.push({lists[i]->val, lists[i]});
  }

  if (minHeap.empty())
    return NULL;

  ListNode *node = new ListNode();
  ListNode *head = node;
  while (1)
  {
    pair<int, ListNode *> x = minHeap.top();
    minHeap.pop();
    node->val = x.first;
    if (x.second->next != NULL)
    {
      x.second = x.second->next;
      minHeap.push({x.second->val, x.second});
    }
    if (!minHeap.empty())
    {
      node->next = new ListNode();
      node = node->next;
    }
    else
      break;
  }
  return head;
}

int main()
{

  return 0;
}