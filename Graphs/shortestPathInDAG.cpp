#include <bits/stdc++.h>

using namespace std;

void toposort(int node, vector<pair<int, int>> adj[], vector<int> &vis, stack<int> &st)
{
  vis[node] = 1;
  for (auto i : adj[node])
  {
    if (vis[i.first] == 0)
      toposort(i.first, adj, vis, st);
  }
  st.push(node);
}

vector<int> shortestPath(int N, int M, vector<int> edges[])
{
  vector<pair<int, int>> adj[N];
  for (int i = 0; i < M; i++)
  {
    int u = edges[i][0];
    int v = edges[i][1];
    int wt = edges[i][2];
    adj[u].push_back({v, wt});
  }
  vector<int> vis(N, 0);
  stack<int> st;
  for (int i = 0; i < N; i++)
  {
    if (!vis[i])
      toposort(i, adj, vis, st);
  }
  vector<int> dist(N, INT_MAX);
  dist[0] = 0;
  while (!st.empty())
  {
    int node = st.top();
    st.pop();
    for (auto it : adj[node])
    {
      int v = it.first;
      int wt = it.second;
      if (dist[node] + wt < dist[v])
        dist[v] = dist[node] + wt;
    }
  }
  return dist;
}

int main()
{
  int N, M;
  cin >> N >> M;
  vector<int> edges[M];
  for (int i = 0; i < M; i++)
  {
    int u, v, wt;
    cin >> u >> v >> wt;
    edges[i].push_back(u);
    edges[i].push_back(v);
    edges[i].push_back(wt);
  }
  vector<int> ans = shortestPath(N, M, edges);
  for (int i = 0; i < N; i++)
    cout << ans[i] << " ";
  cout << "\n";

  return 0;
}