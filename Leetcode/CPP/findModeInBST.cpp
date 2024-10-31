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

void inorder(TreeNode *root, map<int, int> &freq)
{
  if (root == NULL)
    return;
  inorder(root->left, freq);
  freq[root->val]++;
  inorder(root->right, freq);
}

vector<int> findMode(TreeNode *root)
{
  map<int, int> freq;
  inorder(root, freq);
  vector<int> ans;
  int maxi = INT_MIN;
  for (auto i = freq.begin(); i != freq.end(); i++)
    if (i->second > maxi)
      maxi = i->second;
  for (auto i = freq.begin(); i != freq.end(); i++)
    if (i->second == maxi)
      ans.push_back(i->first);
  return ans;
}

int main()
{

  return 0;
}