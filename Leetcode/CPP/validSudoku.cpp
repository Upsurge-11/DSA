#include <bits/stdc++.h>

using namespace std;

bool isValidSudoku(vector<vector<char>> &board)
{
  vector<vector<bool>> row(9, vector<bool>(9, false));
  vector<vector<bool>> col(9, vector<bool>(9, false));
  vector<vector<bool>> box(9, vector<bool>(9, false));

  for (int i = 0; i < 9; i++)
  {
    for (int j = 0; j < 9; j++)
    {
      if (board[i][j] != '.')
      {
        int num = board[i][j] - '0' - 1;
        int k = i / 3 * 3 + j / 3;
        if (row[i][num] || col[j][num] || box[k][num])
          return false;
        row[i][num] = col[j][num] = box[k][num] = true;
      }
    }
  }
  return true;
}

int main()
{
  vector<vector<char>> board(9, vector<char>(9));

  for (int i = 0; i < 9; i++)
  {
    for (int j = 0; j < 9; j++)
    {
      cin >> board[i][j];
    }
  }

  if (isValidSudoku(board))
    cout << "true";
  else
    cout << "false";

  return 0;
}