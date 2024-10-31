#include <bits/stdc++.h>

using namespace std;

bool dfs(vector<vector<int>> &adj, int src, vector<bool> &vis,
         vector<bool> &incycle) {
  vis[src] = true;
  incycle[src] = true;
  for (auto x : adj[src]) {
    if (!vis[x] && dfs(adj, x, vis, incycle)) {
      return true;
    } else if (incycle[x] == true) {
      return true;
    }
  }
  incycle[src] = false;
  return false;
}
vector<int> eventualSafeNodes(vector<vector<int>> &graph) {
  int n = graph.size();
  vector<bool> vis(n, false);
  vector<bool> incycle(n, false);
  for (int i = 0; i < n; i++) {
    if (!vis[i])
      dfs(graph, i, vis, incycle);
  }
  vector<int> ans;
  for (int i = 0; i < incycle.size(); i++) {
    if (!incycle[i])
      ans.push_back(i);
  }
  return ans;
}

int main() {
  int n;
  cin >> n;
  vector<vector<int>> graph(n);
  for (int i = 0; i < n; i++) {
    int m;
    cin >> m;
    for (int j = 0; j < m; j++) {
      int x;
      cin >> x;
      graph[i].push_back(x);
    }
  }
  vector<int> ans = eventualSafeNodes(graph);
  for (auto x : ans) {
    cout << x << " ";
  }
  cout << "\n";
  return 0;
}
