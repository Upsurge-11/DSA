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

int minCostConnectPoints(vector<vector<int>> &points)
{
  int n = points.size();
  vector<pair<int, pair<int, int>>> edges;
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      int x = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
      edges.push_back({x, {i, j}});
    }
  }
  sort(edges.begin(), edges.end());
  int ans = 0;
  DisjointSet ds(n);
  for (auto edge : edges)
  {
    int u = edge.second.first;
    int v = edge.second.second;
    int w = edge.first;
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
  int n;
  cin >> n;
  vector<vector<int>> points(n, vector<int>(2));
  for (int i = 0; i < n; i++)
    cin >> points[i][0] >> points[i][1];
  cout << minCostConnectPoints(points) << "\n";
  return 0;
}