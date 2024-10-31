#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>> &graph, int node, vector<bool> &visited,
         int &count)
{
  visited[node] = true;
  count++;
  for (int i = 0; i < graph[node].size(); i++)
  {
    if (!visited[graph[node][i]])
    {
      dfs(graph, graph[node][i], visited, count);
    }
  }
}

int maximumDetonation(vector<vector<int>> &bombs)
{
  int n = bombs.size();
  vector<vector<int>> graph(n);
  for (int i = 0; i < n; i++)
  {
    long long x1 = bombs[i][0], y1 = bombs[i][1], r1 = bombs[i][2];
    for (int j = 0; j < n; j++)
    {
      if (i == j)
        continue;
      long long x2 = bombs[j][0], y2 = bombs[j][1], r2 = bombs[j][2];
      long long x = abs(x1 - x2), y = abs(y1 - y2);
      if (x * x + y * y <= r1 * r1)
      {
        graph[i].push_back(j);
      }
    }
  }
  int ans = INT_MIN;
  for (int i = 0; i < n; i++)
  {
    int count = 0;
    vector<bool> visited(n, false);
    dfs(graph, i, visited, count);
    ans = max(ans, count);
  }
  return ans;
}

int main()
{
  int n;
  cin >> n;
  vector<vector<int>> bombs(n, vector<int>(3));
  for (int i = 0; i < n; i++)
  {
    cin >> bombs[i][0] >> bombs[i][1] >> bombs[i][2];
  }
  cout << maximumDetonation(bombs) << "\n";

  return 0;
}
