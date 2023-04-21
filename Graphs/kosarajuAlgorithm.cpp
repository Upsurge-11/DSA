#include <bits/stdc++.h>

using namespace std;

void dfs(int node, vector<int> adj[], vector<int> &vis, stack<int> &st)
{
  vis[node] = 1;
  for (auto it : adj[node])
  {
    if (!vis[it])
      dfs(it, adj, vis, st);
  }
  st.push(node);
}

void dfs2(int node, vector<int> adj[], vector<int> &vis)
{
  vis[node] = 1;
  for (auto it : adj[node])
  {
    if (!vis[it])
      dfs2(it, adj, vis);
  }
}

int kosaraju(int V, vector<int> adj[])
{
  vector<int> vis(V, 0);
  stack<int> st;
  for (int i = 0; i < V; i++)
  {
    if (!vis[i])
      dfs(i, adj, vis, st);
  }
  vector<int> transpose[V];
  for (int i = 0; i < V; i++)
  {
    vis[i] = 0;
    vis[i] = 0;
    for (auto it : adj[i])
      transpose[it].push_back(i);
  }
  int count = 0;
  while (!st.empty())
  {
    int node = st.top();
    st.pop();
    if (!vis[node])
    {
      dfs2(node, transpose, vis);
      count++;
    }
  }
  return count;
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
  cout << kosaraju(V, adj) << "\n";

  return 0;
}