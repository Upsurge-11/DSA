#include <bits/stdc++.h>

using namespace std;

int minReorder(int n, vector<vector<int>> &connections)
{
  int ans = 0;
  vector<vector<int>> graph(n);
  vector<bool> visited(n, false);
  for (auto &c : connections)
  {
    graph[c[0]].push_back(c[1]);
    graph[c[1]].push_back(-c[0]);
  }
  queue<int> q;
  q.push(0);
  visited[0] = true;
  while (!q.empty())
  {
    int node = q.front();
    q.pop();
    for (auto &i : graph[node])
    {
      if (visited[abs(i)])
        continue;
      if (i > 0)
        ans++;
      q.push(abs(i));
      visited[abs(i)] = true;
    }
  }
  return ans;
}

int main()
{
  int n, roads;
  cin >> n >> roads;
  vector<vector<int>> connections(roads, vector<int>(2));
  for (int i = 0; i < roads; i++)
    cin >> connections[i][0] >> connections[i][1];
  cout << minReorder(n, connections) << "\n";

  return 0;
}