#include <bits/stdc++.h>

using namespace std;

void dfs(int row, int col, vector<vector<char>> &board, vector<vector<int>> &vis)
{
  if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size() || vis[row][col] || board[row][col] == 'X')
    return;
  vis[row][col] = 1;
  dfs(row + 1, col, board, vis);
  dfs(row - 1, col, board, vis);
  dfs(row, col + 1, board, vis);
  dfs(row, col - 1, board, vis);
}

vector<vector<char>> fill(int n, int m, vector<vector<char>> &board)
{
  vector<vector<char>> res(n, vector<char>(m, 'X'));
  vector<vector<int>> vis(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++)
  {
    if (!vis[i][0] && board[i][0] == '0')
      dfs(i, 0, board, vis);
    if (!vis[i][m - 1] && board[i][m - 1] == '0')
      dfs(i, m - 1, board, vis);
  }

  for (int i = 0; i < m; i++)
  {
    if (!vis[0][i] && board[0][i] == '0')
      dfs(0, i, board, vis);
    if (!vis[n - 1][i] && board[n - 1][i] == '0')
      dfs(n - 1, i, board, vis);
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (board[i][j] == '0' && !vis[i][j])
        res[i][j] = 'X';
      else
        res[i][j] = '0';
    }
  }
  return res;
}

int main()
{
  int row, col;
  cin >> row >> col;
  vector<vector<char>> board(row, vector<char>(col));
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < col; j++)
      cin >> board[i][j];
  }
  vector<vector<char>> res = fill(row, col, board);
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < col; j++)
      cout << res[i][j] << " ";
    cout << "\n";
  }

  return 0;
}