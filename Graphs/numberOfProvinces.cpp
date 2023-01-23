#include <bits/stdc++.h>

using namespace std;

void dfs(int node, vector<int> adj[], vector<int> &vis)
{
  vis[node] = 1;
  for (auto it : adj[node])
  {
    if (!vis[it])
      dfs(it, adj, vis);
  }
}

int newProvinces(vector<int> adj[], int V)
{
  vector<int> vis(V, 0);
  int count = 0;
  for (int i = 0; i < V; i++)
  {
    if (!vis[i])
    {
      count++;
      dfs(i, adj, vis);
    }
  }
  return count;
}

int main()
{

  int n, m;
  cin >> n >> m;
  vector<int> adj[n + 1];
  for (int i = 0; i < m; i++)
  {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  cout << newProvinces(adj, n) << "\n";

  return 0;
}