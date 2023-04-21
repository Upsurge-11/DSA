#include <bits/stdc++.h>

using namespace std;

int timer = 0;

void dfs(int node, int parent, vector<int> &vis, vector<int> &tin, vector<int> &low, vector<int> &isArticulation, vector<int> adj[])
{
  vis[node] = 1;
  tin[node] = low[node] = timer++;
  int children = 0;
  for (auto it : adj[node])
  {
    if (it == parent)
      continue;
    if (vis[it])
      low[node] = min(low[node], tin[it]);
    else
    {
      dfs(it, node, vis, tin, low, isArticulation, adj);
      if (low[it] >= tin[node] && parent != -1)
        isArticulation[node] = 1;
      low[node] = min(low[node], low[it]);
      children++;
    }
  }
  if (parent == -1 && children > 1)
    isArticulation[node] = 1;
}

vector<int> articulationPoints(int V, vector<int> adj[])
{
  vector<int> vis(V, 0);
  vector<int> tin(V);
  vector<int> low(V);
  vector<int> isArticulationPoint(V, 0);
  for (int i = 0; i < V; i++)
  {
    if (!vis[i])
      dfs(i, -1, vis, tin, low, isArticulationPoint, adj);
  }
  vector<int> ans;
  for (int i = 0; i < V; i++)
  {
    if (isArticulationPoint[i])
      ans.push_back(i);
  }
  if (ans.size() == 0)
    ans.push_back(-1);
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
    adj[v].push_back(u);
  }
  vector<int> ans = articulationPoints(V, adj);
  for (auto it : ans)
    cout << it << " ";
  cout << "\n";

  return 0;
}