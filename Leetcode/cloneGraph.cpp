#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
  int val;
  vector<Node *> neighbors;
  Node()
  {
    val = 0;
    neighbors = vector<Node *>();
  }
  Node(int _val)
  {
    val = _val;
    neighbors = vector<Node *>();
  }
  Node(int _val, vector<Node *> _neighbors)
  {
    val = _val;
    neighbors = _neighbors;
  }
};

Node *cloneGraph(Node *node)
{
  if (node == NULL)
    return NULL;
  unordered_map<Node *, Node *> m;
  queue<Node *> q;
  q.push(node);
  m[node] = new Node(node->val);
  while (!q.empty())
  {
    Node *curr = q.front();
    q.pop();
    for (auto neighbor : curr->neighbors)
    {
      if (m.find(neighbor) == m.end())
      {
        m[neighbor] = new Node(neighbor->val);
        q.push(neighbor);
      }
      m[curr]->neighbors.push_back(m[neighbor]);
    }
  }
  return m[node];
}

int main()
{

  return 0;
}