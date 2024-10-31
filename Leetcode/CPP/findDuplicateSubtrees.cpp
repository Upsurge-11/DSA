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

string serializeSubtrees(TreeNode *node, unordered_map<string, int> &freqSubtree, vector<TreeNode *> &ans)
{
  if (!node)
    return "N";
  string left = serializeSubtrees(node->left, freqSubtree, ans);
  string right = serializeSubtrees(node->right, freqSubtree, ans);
  string s = left + "," + right + "," + to_string(node->val);
  freqSubtree[s]++;
  if (freqSubtree[s] == 2)
    ans.push_back(node);
  return s;
}

vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
{
  unordered_map<string, int> freqSubtree;
  vector<TreeNode *> ans;
  serializeSubtrees(root, freqSubtree, ans);
  return ans;
}

int main()
{

  return 0;
}