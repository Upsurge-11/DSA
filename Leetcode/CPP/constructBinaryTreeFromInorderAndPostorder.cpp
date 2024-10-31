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

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
  if (inorder.size() == 0)
    return NULL;
  int rootVal = postorder[postorder.size() - 1];
  TreeNode *root = new TreeNode(rootVal);
  int rootIndex = 0;
  for (int i = 0; i < inorder.size(); i++)
  {
    if (inorder[i] == rootVal)
    {
      rootIndex = i;
      break;
    }
  }
  vector<int> leftInorder(inorder.begin(), inorder.begin() + rootIndex);
  vector<int> rightInorder(inorder.begin() + rootIndex + 1, inorder.end());
  vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftInorder.size());
  vector<int> rightPostorder(postorder.begin() + leftInorder.size(), postorder.end() - 1);
  root->left = buildTree(leftInorder, leftPostorder);
  root->right = buildTree(rightInorder, rightPostorder);
  return root;
}

int main()
{

  return 0;
}