#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode() : val(0), left(NULL), right(NULL) {}
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

int minDepth(TreeNode *root) {
  if (root == NULL)
    return 0;
  if (root->left == NULL && root->right == NULL)
    return 1;
  if (root->left == NULL)
    return minDepth(root->right) + 1;
  if (root->right == NULL)
    return minDepth(root->left) + 1;
  return min(minDepth(root->left), minDepth(root->right)) + 1;
}

int main() { return 0; }
