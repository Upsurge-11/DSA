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

int sumNumbers(TreeNode *root)
{
  if (root == nullptr)
    return 0;
  int sum = 0;
  queue<TreeNode *> q;
  q.push(root);
  while (!q.empty())
  {
    TreeNode *node = q.front();
    q.pop();
    if (node->left == nullptr && node->right == nullptr)
      sum += node->val;
    if (node->left != nullptr)
    {
      node->left->val += node->val * 10;
      q.push(node->left);
    }
    if (node->right != nullptr)
    {
      node->right->val += node->val * 10;
      q.push(node->right);
    }
  }
  return sum;
}

int main()
{

  return 0;
}