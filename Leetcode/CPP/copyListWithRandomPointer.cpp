#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
  int val;
  Node *next;
  Node *random;

  Node(int _val)
  {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

Node *func(Node *head, unordered_map<Node *, Node *> &mp)
{
  if (!head)
    return head;
  if (mp.count(head))
    return mp[head];
  Node *newNode = new Node(head->val);
  mp[head] = newNode;
  newNode->next = func(head->next, mp);
  newNode->random = func(head->random, mp);
  return newNode;
}

Node *copyRandomList(Node *head)
{
  unordered_map<Node *, Node *> mp;
  return func(head, mp);
}

int main()
{

  return 0;
}