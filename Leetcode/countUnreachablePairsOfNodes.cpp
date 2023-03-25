#include <bits/stdc++.h>

using namespace std;

void dfs(vector<int> adj[], int src, vector<bool> &vis, int &counter)
{
  if (vis[src])
    return;
  vis[src] = true;
  counter++;
  for (auto ele : adj[src])
  {
    if (!vis[ele])
      dfs(adj, ele, vis, counter);
  }
}
long long countPairs(int n, vector<vector<int>> &edges)
{
  vector<int> adj[n];
  for (auto edge : edges)
  {
    adj[edge[0]].push_back(edge[1]);
    adj[edge[1]].push_back(edge[0]);
  }
  long long res = 0;
  vector<bool> vis(n, false);
  vector<int> temp;
  for (int i = 0; i < n; i++)
  {
    if (!vis[i])
    {
      int counter = 0;
      dfs(adj, i, vis, counter);
      temp.push_back(counter);
    }
  }
  int total = 0;
  for (int i = 0; i < temp.size(); i++)
  {
    res += (long)((long)temp[i] * (long)(n - total - temp[i]));
    total += temp[i];
  }
  return res;
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> edges(m, vector<int>(2));
  for (int i = 0; i < m; i++)
  {
    cin >> edges[i][0] >> edges[i][1];
  }
  cout << countPairs(n, edges) << endl;

  return 0;
}