#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> distanceK(TreeNode *root, TreeNode *target, int k) {
  vector<int> res;
  unordered_map<TreeNode *, TreeNode *> parent;
  unordered_set<TreeNode *> visited;
  queue<TreeNode *> q;
  q.push(root);
  while (!q.empty()) {
    TreeNode *curr = q.front();
    q.pop();
    if (curr->left) {
      parent[curr->left] = curr;
      q.push(curr->left);
    }
    if (curr->right) {
      parent[curr->right] = curr;
      q.push(curr->right);
    }
  }
  q.push(target);
  visited.insert(target);
  int level = 0;
  while (!q.empty()) {
    int size = q.size();
    if (level == k) {
      for (int i = 0; i < size; ++i) {
        res.push_back(q.front()->val);
        q.pop();
      }
      return res;
    }
    for (int i = 0; i < size; ++i) {
      TreeNode *curr = q.front();
      q.pop();
      if (curr->left && visited.find(curr->left) == visited.end()) {
        q.push(curr->left);
        visited.insert(curr->left);
      }
      if (curr->right && visited.find(curr->right) == visited.end()) {
        q.push(curr->right);
        visited.insert(curr->right);
      }
      if (parent[curr] && visited.find(parent[curr]) == visited.end()) {
        q.push(parent[curr]);
        visited.insert(parent[curr]);
      }
    }
    ++level;
  }
  return res;
}

int main() { return 0; }
