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

int maxLevelSum(TreeNode *root) {
  if (!root)
    return 0;
  int maxSum = INT_MIN, maxLevel = 0, level = 0;
  queue<TreeNode *> q;
  q.push(root);
  while (!q.empty()) {
    int size = q.size(), sum = 0;
    ++level;
    while (size--) {
      TreeNode *node = q.front();
      q.pop();
      sum += node->val;
      if (node->left)
        q.push(node->left);
      if (node->right)
        q.push(node->right);
    }
    if (sum > maxSum) {
      maxSum = sum;
      maxLevel = level;
    }
  }
  return maxLevel;
}

int main() { return 0; }
