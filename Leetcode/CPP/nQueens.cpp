#include <bits/stdc++.h>

using namespace std;

bool isSafe(int row, int col, vector<string> &board, int n)
{
  int temprow = row;
  int tempcol = col;

  while (row >= 0 && col >= 0)
  {
    if (board[row][col] == 'Q')
      return false;
    row--;
    col--;
  }
  row = temprow;
  col = tempcol;
  while (col >= 0)
  {
    if (board[row][col] == 'Q')
      return false;
    col--;
  }
  row = temprow;
  col = tempcol;
  while (row < n && col >= 0)
  {
    if (board[row][col] == 'Q')
      return false;
    row++;
    col--;
  }
  return true;
}

void util(int col, vector<string> &board, vector<vector<string>> &ans, int n)
{
  if (col == n)
  {
    ans.push_back(board);
    return;
  }
  for (int row = 0; row < n; row++)
  {
    if (isSafe(row, col, board, n))
    {
      board[row][col] = 'Q';
      util(col + 1, board, ans, n);
      board[row][col] = '.';
    }
  }
}

vector<vector<string>> solveNQueens(int n)
{
  vector<vector<string>> ans;
  vector<string> board(n);
  string s(n, '.');
  for (int i = 0; i < n; i++)
    board[i] = s;
  util(0, board, ans, n);
  return ans;
}

int main()
{
  int n;
  cin >> n;
  vector<vector<string>> ans = solveNQueens(n);

  for (int i = 0; i < ans.size(); i++)
  {
    for (int j = 0; j < ans[i].size(); j++)
    {
      cout << ans[i][j] << " ";
    }
    cout << "\n";
  }

  return 0;
}