#include <bits/stdc++.h>

using namespace std;

bool canWalk(vector<vector<int>> &cells, int row, int col, int dayAt) {
  int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
  vector<vector<bool>> grid(row, vector<bool>(col, 0));
  for (int i = 0; i < dayAt; ++i)
    grid[cells[i][0] - 1][cells[i][1] - 1] = 1;
  queue<pair<int, int>> q;
  for (int c = 0; c < col; ++c) {
    if (grid[0][c] == 0) {
      q.push({0, c});
      grid[0][c] = 1;
    }
  }
  while (!q.empty()) {
    auto t = q.front();
    int r = t.first, c = t.second;
    q.pop();
    if (r == row - 1)
      return true;
    for (int i = 0; i < 4; ++i) {
      int nr = r + dx[i], nc = c + dy[i];
      if (nr < 0 || nr == row || nc < 0 || nc == col || grid[nr][nc] == 1)
        continue;
      grid[nr][nc] = 1;
      q.push({nr, nc});
    }
  }
  return false;
}

int latestDayToCross(int row, int col, vector<vector<int>> &cells) {
  int low = 1, high = cells.size(), ans = 0;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (canWalk(cells, row, col, mid)) {
      ans = mid;
      low = mid + 1;
    } else
      high = mid - 1;
  }
  return ans;
}

int main() {
  int row, col, x;
  cin >> row >> col >> x;
  vector<vector<int>> cells(x, vector<int>(2));
  for (int i = 0; i < x; i++)
    cin >> cells[i][0] >> cells[i][1];
  cout << latestDayToCross(row, col, cells) << "\n";
  return 0;
}
