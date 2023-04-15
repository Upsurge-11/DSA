#include <bits/stdc++.h>

using namespace std;

bool dfs(int node, vector<int> &visited, vector<int> &pathVisited, vector<int> adj[], vector<int> &check)
{
  visited[node] = 1;
  pathVisited[node] = 1;
  check[node] = 0;
  for (auto it : adj[node])
  {
    if (!visited[it])
    {
      if (dfs(it, visited, pathVisited, adj, check))
      {
        check[node] = 0;
        return true;
      }
    }
    else if (pathVisited[it])
    {
      check[node] = 0;
      return true;
    }
  }
  pathVisited[node] = 0;
  check[node] = 1;
  return false;
}

vector<int> eventualSafeNodes(int V, vector<int> adj[])
{
  vector<int> visited(V, 0);
  vector<int> pathVisited(V, 0);
  vector<int> check(V, 0);
  vector<int> ans;
  for (int i = 0; i < V; i++)
  {
    if (!visited[i])
    {
      if (!dfs(i, visited, pathVisited, adj, check))
        ans.push_back(i);
    }
  }
  for (int i = 0; i < V; i++)
  {
    if (check[i] == 1)
      ans.push_back(i);
  }
  return ans;
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
  vector<int> ans = eventualSafeNodes(V, adj);
  for (auto it : ans)
    cout << it << " ";
  cout << "\n";

  return 0;
}