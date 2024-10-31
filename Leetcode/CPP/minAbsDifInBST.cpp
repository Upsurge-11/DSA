#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

void inorder(TreeNode *root, TreeNode *&prev, int &minDiff) {
  if (!root)
    return;
  inorder(root->left, prev, minDiff);
  if (prev)
    minDiff = min(minDiff, root->val - prev->val);
  prev = root;
  inorder(root->right, prev, minDiff);
}

int getMinimumDifference(TreeNode *root) {
  int minDiff = INT_MAX;
  TreeNode *prev = NULL;
  inorder(root, prev, minDiff);
  return minDiff;
}

int main() { return 0; }
