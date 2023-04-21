#include <bits/stdc++.h>

using namespace std;

int spanningTree(int V, vector<vector<int>> adj[])
{
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  vector<bool> visited(V, false);
  int sum = 0;
  pq.push({0, 0});
  while (!pq.empty())
  {
    auto it = pq.top();
    pq.pop();
    int node = it.second;
    int weight = it.first;
    if (visited[node])
      continue;
    visited[node] = true;
    sum += weight;
    for (auto it : adj[node])
    {
      if (!visited[it[0]])
        pq.push({it[1], it[0]});
    }
  }
  return sum;
}

int main()
{
  int V, E;
  cin >> V >> E;
  vector<vector<int>> adj[V];
  for (int i = 0; i < E; i++)
  {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }
  cout << spanningTree(V, adj) << "\n";

  return 0;
}