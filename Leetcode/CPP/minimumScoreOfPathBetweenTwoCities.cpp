#include <bits/stdc++.h>

using namespace std;

int minScore(int n, vector<vector<int>> &roads)
{
  int ans = INT_MAX;
  vector<vector<pair<int, int>>> graph(n + 1);
  for (auto edge : roads)
  {
    graph[edge[0]].push_back({edge[1], edge[2]});
    graph[edge[1]].push_back({edge[0], edge[2]});
  }

  vector<int> visited(n + 1, 0);
  queue<int> q;
  q.push(1);
  visited[1] = 1;
  while (!q.empty())
  {
    auto node = q.front();
    q.pop();
    for (auto &[v, dis] : graph[node])
    {
      ans = min(ans, dis);
      if (visited[v] == 0)
      {
        visited[v] = 1;
        q.push(v);
      }
    }
  }

  return ans;
}

int main()
{
  int n, size;
  cin >> n >> size;
  vector<vector<int>> roads(size, vector<int>(3));

  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < 3; j++)
      cin >> roads[i][j];
  }

  cout << minScore(n, roads) << "\n";

  return 0;
}