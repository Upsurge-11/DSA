#include <bits/stdc++.h>

using namespace std;

int timer = 1;

void dfs(int node, int parent, vector<int> &vis, vector<int> adj[], vector<int> &tin, vector<int> &low, vector<vector<int>> &bridges)
{
  vis[node] = 1;
  tin[node] = low[node] = timer++;
  for (auto it : adj[node])
  {
    if (it == parent)
      continue;
    if (!vis[it])
    {
      dfs(it, node, vis, adj, tin, low, bridges);
      low[node] = min(low[node], low[it]);
      if (low[it] > tin[node])
        bridges.push_back({it, node});
    }
    else if (it != parent)
      low[node] = min(low[node], tin[it]);
  }
}

vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
{
  vector<int> adj[n];
  for (auto it : connections)
  {
    adj[it[0]].push_back(it[1]);
    adj[it[1]].push_back(it[0]);
  }
  vector<int> vis(n, 0);
  vector<int> tin(n, 0);
  vector<int> low(n, 0);
  vector<vector<int>> ans;
  dfs(0, -1, vis, adj, tin, low, ans);
  return ans;
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> connections(m, vector<int>(2));
  for (int i = 0; i < m; i++)
    cin >> connections[i][0] >> connections[i][1];
  vector<vector<int>> ans = criticalConnections(n, connections);
  for (auto it : ans)
    cout << it[0] << " " << it[1] << "\n";

  return 0;
}