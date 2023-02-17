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

int minDiffInBST(TreeNode *root)
{
  int minDiff = INT_MAX;
  stack<TreeNode *> st;
  TreeNode *prev = nullptr;
  while (root != nullptr || !st.empty())
  {
    while (root != nullptr)
    {
      st.push(root);
      root = root->left;
    }
    root = st.top();
    st.pop();
    if (prev != nullptr)
    {
      minDiff = min(minDiff, root->val - prev->val);
    }
    prev = root;
    root = root->right;
  }
  return minDiff;
}

int main()
{

  return 0;
}