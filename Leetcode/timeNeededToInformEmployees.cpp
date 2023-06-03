#include <bits/stdc++.h>

using namespace std;

int numOfMinutes(int n, int headID, vector<int> &manager,
                 vector<int> &informTime) {
  vector<vector<int>> adj(n);
  for (int i = 0; i < n; i++) {
    if (manager[i] != -1) {
      adj[manager[i]].push_back(i);
    }
  }
  queue<pair<int, int>> q;
  q.push({headID, 0});
  int ans = 0;
  while (!q.empty()) {
    int u = q.front().first;
    int time = q.front().second;
    q.pop();
    ans = max(ans, time);
    for (auto v : adj[u]) {
      q.push({v, time + informTime[u]});
    }
  }
  return ans;
}

int main() {
  int n;
  cin >> n;
  int headID;
  cin >> headID;
  vector<int> manager(n), informTime(n);
  for (int i = 0; i < n; i++) {
    cin >> manager[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> informTime[i];
  }
  cout << numOfMinutes(n, headID, manager, informTime) << "\n";
  return 0;
}
