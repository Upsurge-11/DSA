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

vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>> &edgeList, vector<vector<int>> &queries)
{
  vector<bool> ans(queries.size());
  vector<int> idx(queries.size());
  for (int i = 0; i < queries.size(); i++)
    idx[i] = i;
  sort(idx.begin(), idx.end(), [&](int a, int b)
       { return queries[a][2] < queries[b][2]; });
  sort(edgeList.begin(), edgeList.end(), [&](vector<int> &a, vector<int> &b)
       { return a[2] < b[2]; });
  DisjointSet ds(n);
  int j = 0;
  for (int i = 0; i < queries.size(); i++)
  {
    while (j < edgeList.size() && edgeList[j][2] < queries[idx[i]][2])
    {
      ds.unionBySize(edgeList[j][0], edgeList[j][1]);
      j++;
    }
    ans[idx[i]] = ds.findParent(queries[idx[i]][0]) == ds.findParent(queries[idx[i]][1]);
  }
  return ans;
}

int main()
{
  int n, e;
  cin >> n >> e;
  vector<vector<int>> edgeList;
  vector<vector<int>> queries;
  int u, v, w;
  while (e--)
  {
    cin >> u >> v >> w;
    edgeList.push_back({u, v, w});
  }
  int q;
  cin >> q;
  while (q--)
  {
    cin >> u >> v >> w;
    queries.push_back({u, v, w});
  }
  vector<bool> ans = distanceLimitedPathsExist(n, edgeList, queries);
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i] << " ";
  cout << "\n";

  return 0;
}