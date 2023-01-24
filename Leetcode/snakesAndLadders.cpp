#include <bits/stdc++.h>

using namespace std;

int snakesAndLadders(vector<vector<int>> &board)
{
  int n = board.size();
  vector<int> moves(n * n + 1, 0);
  int i = n - 1, j = 0, idx = 1, even = 0;
  while (i >= 0 && j >= 0)
  {
    if (board[i][j] == -1)
      moves[idx++] = 0;
    else
      moves[idx++] = board[i][j];
    if (even % 2 == 0)
      j++;
    else
      j--;
    if (j >= n)
    {
      i--;
      j--;
      even++;
    }
    if (j < 0)
    {
      i--;
      j++;
      even++;
    }
  }
  queue<int> q;
  q.push(1);
  vector<bool> visited(n * n + 1, false);
  visited[1] = true;
  int level = 0;
  while (!q.empty())
  {
    int size = q.size();
    while (size--)
    {
      int curr = q.front();
      q.pop();
      if (curr == n * n)
        return level;
      for (int dice = 1; dice <= 6; dice++)
      {
        int next = curr + dice;
        if (next > n * n)
          break;
        if (moves[next] != 0)
          next = moves[next];
        if (!visited[next])
        {
          visited[next] = true;
          q.push(next);
        }
      }
    }
    level++;
  }
  return -1;
}

int main()
{
  int n;
  cin >> n;
  vector<vector<int>> board(n, vector<int>(n));
  cout << snakesAndLadders(board) << "\n";

  return 0;
}