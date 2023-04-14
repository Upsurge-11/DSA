#include <bits/stdc++.h>

using namespace std;

bool dfs(int node, int col, vector<int> &color, vector<int> adj[])
{
  color[node] = col;
  for (auto it : adj[node])
  {
    if (color[it] == -1)
    {
      if (!dfs(it, 1 - col, color, adj))
        return false;
    }
    else if (color[it] == color[node])
      return false;
  }
  return true;
}

bool isBipartite(int V, vector<int> adj[])
{
  vector<int> color(V, -1);
  for (int i = 0; i < V; i++)
  {
    if (color[i] == -1)
    {
      if (!dfs(i, 0, color, adj))
        return false;
    }
  }
  return true;
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
    adj[v].push_back(u);
  }
  if (isBipartite(V, adj))
    cout << "Yes";
  else
    cout << "No";

  return 0;
}