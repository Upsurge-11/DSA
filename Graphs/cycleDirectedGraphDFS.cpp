#include <bits/stdc++.h>

using namespace std;

bool dfs(int node, vector<int> &visited, vector<int> &pathVisited, vector<int> adj[])
{
  visited[node] = 1;
  pathVisited[node] = 1;
  for (auto it : adj[node])
  {
    if (!visited[it])
    {
      if (dfs(it, visited, pathVisited, adj))
        return true;
    }
    else if (pathVisited[it])
      return true;
  }
  pathVisited[node] = 0;
  return false;
}

bool isCyclic(int V, vector<int> adj[])
{
  vector<int> visited(V, 0);
  vector<int> pathVisited(V, 0);
  for (int i = 0; i < V; i++)
  {
    if (dfs(i, visited, pathVisited, adj))
      return true;
  }
  return false;
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
  return 0;
}