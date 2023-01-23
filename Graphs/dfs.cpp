#include <bits/stdc++.h>

using namespace std;

void dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &ans)
{
  vis[node] = 1;
  ans.push_back(node);
  for (auto it : adj[node])
  {
    if (!vis[it])
    {
      dfs(it, adj, vis, ans);
    }
  }
}

vector<int> dfsOfGraph(int V, vector<int> adj[])
{
  vector<int> vis(V, 0);
  int start = 0;
  vector<int> ans;
  dfs(start, adj, vis, ans);
  return ans;
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

  vector<int> ans = dfsOfGraph(n, adj);

  for (int i = 0; i < ans.size(); i++)
    cout << ans[i] << " ";
  cout << "\n";

  return 0;
}