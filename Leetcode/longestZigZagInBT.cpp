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

int maxZigZag(TreeNode *node, bool isLeft, int cnt)
{
  if (!node)
    return cnt;
  if (isLeft)
    return max(maxZigZag(node->right, false, cnt + 1), maxZigZag(node->left, true, 0));
  return max(maxZigZag(node->left, true, cnt + 1), maxZigZag(node->right, false, 0));
}

int longestZigZag(TreeNode *root)
{
  return max(maxZigZag(root->left, true, 0), maxZigZag(root->right, false, 0));
}

int main()
{

  return 0;
}