#include <bits/stdc++.h>

using namespace std;

int minimumEffortPath(vector<vector<int>> &heights)
{
  int n = heights.size(), m = heights[0].size();
  vector<int> dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};
  priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
  vector<vector<int>> dis(n, vector<int>(m, INT_MAX));
  dis[0][0] = 0;
  pq.push({0, {0, 0}});
  while (!pq.empty())
  {
    pair<int, pair<int, int>> curr = pq.top();
    pq.pop();
    int d = curr.first, r = curr.second.first, c = curr.second.second;
    if (r == n - 1 && c == m - 1)
      return d;
    for (int i = 0; i < 4; ++i)
    {
      int nx = r + dx[i], ny = c + dy[i];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m)
        continue;
      int nd = max(d, abs(heights[nx][ny] - heights[r][c]));
      if (nd < dis[nx][ny])
      {
        dis[nx][ny] = nd;
        pq.push({nd, {nx, ny}});
      }
    }
  }
  return 0;
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> heights(n, vector<int>(m));
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      cin >> heights[i][j];
  cout << minimumEffortPath(heights) << "\n";
  return 0;
}