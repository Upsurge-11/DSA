#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *constructBST(ListNode *l, ListNode *r)
{
  if (l == r)
    return nullptr;
  ListNode *slow = l, *fast = l;
  while (fast != r && fast->next != r)
  {
    slow = slow->next;
    fast = fast->next->next;
  }
  TreeNode *root = new TreeNode(slow->val);
  root->left = constructBST(l, slow);
  root->right = constructBST(slow->next, r);
  return root;
}

TreeNode *sortedListToBST(ListNode *head)
{
  if (head == nullptr)
    return nullptr;
  if (head->next == nullptr)
  {
    TreeNode *root = new TreeNode(head->val);
    return root;
  }
  return constructBST(head, nullptr);
}

int main()
{

  return 0;
}