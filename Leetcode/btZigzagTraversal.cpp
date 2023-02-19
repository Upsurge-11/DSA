#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
  vector<vector<int>> res;
  if (root == nullptr)
    return res;
  queue<TreeNode *> q;
  q.push(root);
  bool leftToRight = true;
  while (!q.empty())
  {
    int size = q.size();
    vector<int> level(size);
    for (int i = 0; i < size; i++)
    {
      TreeNode *node = q.front();
      q.pop();
      int index = leftToRight ? i : (size - 1 - i);
      level[index] = node->val;
      if (node->left != nullptr)
        q.push(node->left);
      if (node->right != nullptr)
        q.push(node->right);
    }
    res.push_back(level);
    leftToRight = !leftToRight;
  }
  return res;
}

int main()
{

  return 0;
}