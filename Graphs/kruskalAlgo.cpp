#include <bits/stdc++.h>

using namespace std;

class DisjointSet
{
  vector<int> parent, rank, size;

public:
  DisjointSet(int n)
  {
    rank.resize(n + 1, 0);
    parent.resize(n + 1);
    size.resize(n + 1, 1);
    for (int i = 0; i <= n; i++)
      parent[i] = i;
  }

  int findParent(int node)
  {
    if (node == parent[node])
      return node;
    return parent[node] = findParent(parent[node]);
  }

  void unionByRank(int u, int v)
  {
    int ultimateParentU = findParent(u);
    int ultimateParentV = findParent(v);
    if (ultimateParentU == ultimateParentV)
      return;
    if (rank[ultimateParentU] < rank[ultimateParentV])
      parent[ultimateParentU] = ultimateParentV;
    else if (rank[ultimateParentU] > rank[ultimateParentV])
      parent[ultimateParentV] = ultimateParentU;
    else
    {
      parent[ultimateParentV] = ultimateParentU;
      rank[ultimateParentU]++;
    }
  }

  void unionBySize(int u, int v)
  {
    int ultimateParentU = findParent(u);
    int ultimateParentV = findParent(v);
    if (ultimateParentU == ultimateParentV)
      return;
    if (size[ultimateParentU] < size[ultimateParentV])
    {
      parent[ultimateParentU] = ultimateParentV;
      size[ultimateParentV] += size[ultimateParentU];
    }
    else
    {
      parent[ultimateParentV] = ultimateParentU;
      size[ultimateParentU] += size[ultimateParentV];
    }
  }
};

int spanningTree(int V, vector<vector<int>> adj[])
{
  vector<pair<int, pair<int, int>>> edges;
  for (int i = 0; i < V; i++)
  {
    for (auto it : adj[i])
    {
      int u = i;
      int v = it[0];
      int w = it[1];
      edges.push_back({w, {u, v}});
    }
  }
  sort(edges.begin(), edges.end());
  int ans = 0;
  for (auto it : edges)
  {
    int u = it.second.first;
    int v = it.second.second;
    int w = it.first;
    DisjointSet ds(V);
    if (ds.findParent(u) != ds.findParent(v))
    {
      ds.unionBySize(u, v);
      ans += w;
    }
  }
  return ans;
}

int main()
{
  int V, E;
  cin >> V >> E;
  vector<vector<int>> adj[V];
  for (int i = 0; i < E; i++)
  {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }
  cout << spanningTree(V, adj) << "\n";

  return 0;
}