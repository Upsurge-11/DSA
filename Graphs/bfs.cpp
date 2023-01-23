#include <bits/stdc++.h>

using namespace std;

vector<int> bfsOfGraph(int V, vector<int> adj[])
{
  vector<int> vis(V, 0);
  vis[0] = 1;
  queue<int> q;
  q.push(0);
  vector<int> bfs;
  while (!q.empty())
  {
    int node = q.front();
    q.pop();
    bfs.push_back(node);
    for (auto it : adj[node])
    {
      if (!vis[it])
      {
        vis[it] = 1;
        q.push(it);
      }
    }
  }
  return bfs;
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

  vector<int> ans = bfsOfGraph(n, adj);

  for (int i = 0; i < ans.size(); i++)
    cout << ans[i] << " ";
  cout << "\n";

  return 0;
}