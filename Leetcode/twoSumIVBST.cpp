#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
  bool findTarget(TreeNode *root, int k)
  {
    if (!root)
      return false;
    unordered_set<int> s;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
      TreeNode *node = q.front();
      q.pop();
      if (s.count(k - node->val))
        return true;
      s.insert(node->val);
      if (node->left)
        q.push(node->left);
      if (node->right)
        q.push(node->right);
    }
    return false;
  }
};

int main()
{

  return 0;
}