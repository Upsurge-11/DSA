#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
  bool val;
  bool isLeaf;
  Node *topLeft;
  Node *topRight;
  Node *bottomLeft;
  Node *bottomRight;

  Node()
  {
    val = false;
    isLeaf = false;
    topLeft = NULL;
    topRight = NULL;
    bottomLeft = NULL;
    bottomRight = NULL;
  }

  Node(bool _val, bool _isLeaf)
  {
    val = _val;
    isLeaf = _isLeaf;
    topLeft = NULL;
    topRight = NULL;
    bottomLeft = NULL;
    bottomRight = NULL;
  }

  Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight, Node *_bottomLeft, Node *_bottomRight)
  {
    val = _val;
    isLeaf = _isLeaf;
    topLeft = _topLeft;
    topRight = _topRight;
    bottomLeft = _bottomLeft;
    bottomRight = _bottomRight;
  }
};

bool allSame(const vector<vector<int>> &grid, int i, int j, int w)
{
  return all_of(begin(grid) + i, begin(grid) + i + w, [&](const vector<int> &row)
                { return all_of(begin(row) + j, begin(row) + j + w, [&](int num)
                                { return num == grid[i][j]; }); });
}

Node *helper(const vector<vector<int>> &grid, int i, int j, int w)
{
  if (allSame(grid, i, j, w))
    return new Node(grid[i][j], true);

  Node *node = new Node(true, false);
  node->topLeft = helper(grid, i, j, w / 2);
  node->topRight = helper(grid, i, j + w / 2, w / 2);
  node->bottomLeft = helper(grid, i + w / 2, j, w / 2);
  node->bottomRight = helper(grid, i + w / 2, j + w / 2, w / 2);
  return node;
}

Node *construct(vector<vector<int>> &grid)
{
  return helper(grid, 0, 0, grid[0].size());
}

int main()
{
  int n;
  cin >> n;
  vector<vector<int>> grid(n);
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
      cin >> grid[i][j];
  }
  Node *root = construct(grid);

  return 0;
}