#include <bits/stdc++.h>

using namespace std;

bool isBipartite(int V, vector<int> adj[])
{
  queue<int> q;
  q.push(0);
  vector<int> color(V, -1);
  color[0] = 0;
  while (!q.empty())
  {
    int node = q.front();
    q.pop();
    for (auto it : adj[node])
    {
      if (color[it] == -1)
      {
        color[it] = 1 - color[node];
        q.push(it);
      }
      else if (color[it] == color[node])
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