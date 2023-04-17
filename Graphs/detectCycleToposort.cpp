#include <bits/stdc++.h>

using namespace std;

bool topoSort(int V, vector<int> adj[])
{
  int count = 0;
  vector<int> indegree(V, 0);
  for (int i = 0; i < V; i++)
    for (auto it : adj[i])
      indegree[it]++;
  queue<int> q;
  for (int i = 0; i < V; i++)
  {
    if (!indegree[i])
      q.push(i);
  }
  while (!q.empty())
  {
    int node = q.front();
    q.pop();
    count++;
    for (auto it : adj[node])
    {
      indegree[it]--;
      if (!indegree[it])
        q.push(it);
    }
  }
  return !(count == V);
}

int main()
{
  int V, E;
  cin >> V >> E;
  vector<int> adj[V];
  for (int i = 0; i < E; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
  }

  cout << (topoSort(V, adj) ? "YES" : "NO") << "\n";

  return 0;
}