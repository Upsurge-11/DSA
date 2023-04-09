#include <bits/stdc++.h>

using namespace std;

bool detectCycle(int src, vector<int> adj[], vector<bool> &vis)
{
  vis[src] = true;
  queue<pair<int, int>> q;
  q.push({src, -1});
  while (!q.empty())
  {
    int node = q.front().first;
    int parent = q.back().second;
    q.pop();
    for (auto adjacent : adj[node])
    {
      if (!vis[adjacent])
      {
        vis[adjacent] = true;
        q.push({adjacent, node});
      }
      else if (parent != adjacent)
        return true;
    }
  }
  return false;
}

bool isCycle(int V, vector<int> adj[])
{
  vector<bool> vis(V, false);
  for (int i = 1; i < V; i++)
  {
    if (!vis[i])
    {
      if (detectCycle(i, adj, vis))
        return true;
    }
  }
  return false;
}

int main()
{
  int n;
  cin >> n;
  vector<int> adj[n];
  for (int i = 0; i < n; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  if (isCycle(n, adj))
    cout << "YES\n";
  else
    cout << "NO\n";

  return 0;
}