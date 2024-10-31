#include <bits/stdc++.h>

using namespace std;

vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> &edges)
{
  vector<int> adj[n];
  vector<int> ans;
  vector<int> inCount(n, 0);
  for (int i = 0; i < edges.size(); i++)
  {
    adj[edges[i][0]].push_back(edges[i][1]);
    inCount[edges[i][1]]++;
  }
  for (int i = 0; i < n; i++)
    if (!inCount[i])
      ans.push_back(i);
  return ans;
}

int main()
{
  int n, e;
  cin >> n >> e;
  vector<vector<int>> edges(e, vector<int>(2));
  for (int i = 0; i < e; i++)
    cin >> edges[i][0] >> edges[i][1];
  vector<int> ans = findSmallestSetOfVertices(n, edges);
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i] << " ";
  cout << "\n";
  return 0;
}