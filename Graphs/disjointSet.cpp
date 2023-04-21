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

int main()
{
  DisjointSet ds(7);
  ds.unionByRank(1, 2);
  ds.unionByRank(2, 3);
  ds.unionByRank(4, 5);
  ds.unionByRank(6, 7);
  ds.unionByRank(5, 6);
  if (ds.findParent(3) == ds.findParent(7))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  ds.unionByRank(3, 7);
  if (ds.findParent(3) == ds.findParent(7))
    cout << "Yes\n";
  else
    cout << "No\n";

  return 0;
}