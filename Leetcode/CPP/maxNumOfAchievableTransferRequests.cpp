#include <bits/stdc++.h>

using namespace std;

int func(int idx, int count, vector<int> &indegree,
         vector<vector<int>> &requests) {
  if (idx == requests.size()) {
    for (int i = 0; i < indegree.size(); i++)
      if (indegree[i] != 0)
        return INT_MIN;
    return count;
  }
  int u = requests[idx][0];
  int v = requests[idx][1];
  indegree[u]--;
  indegree[v]++;
  int ans1 = func(idx + 1, count + 1, indegree, requests);
  indegree[u]++;
  indegree[v]--;
  int ans2 = func(idx + 1, count, indegree, requests);
  return max(ans1, ans2);
}

int maximumRequests(int n, vector<vector<int>> &requests) {
  vector<int> indegree(n, 0);
  return func(0, 0, indegree, requests);
}

int main() {
  int n, x;
  cin >> n >> x;
  vector<vector<int>> requests(x, vector<int>(2));
  for (int i = 0; i < x; i++)
    cin >> requests[i][0] >> requests[i][1];
  cout << maximumRequests(n, requests) << "\n";
  return 0;
}
