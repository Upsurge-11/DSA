#include <bits/stdc++.h>

using namespace std;

bool detectCycle(int node, int parent, vector<int> adj[], vector<bool> &vis)
{
  vis[node] = true;
  for (auto ele : adj[node])
  {
    if (!vis[ele])
    {
      if (detectCycle(ele, node, adj, vis))
        return true;
    }
    else if (ele != parent)
      return true;
  }
  return false;
}

bool isCycle(int V, vector<int> adj[])
{
  vector<bool> vis(false);
  for (int i = 1; i < V; i++)
  {
    if (!vis[i])
    {
      if (detectCycle(i, -1, adj, vis))
        return true;
    }
  }
  return false;
}

int main()
{
  int n, x;
  cin >> n >> x;
  vector<int> adj[n];
  for (int i = 0; i < x; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  if (isCycle(n, adj))
    cout << "Yes\n";
  else
    cout << "No\n";
  return 0;
}