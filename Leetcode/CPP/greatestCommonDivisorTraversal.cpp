#include <bits/stdc++.h>

using namespace std;

unordered_set<int> uniqueprimefactors(int n) {
  unordered_set<int> factors;
  for (int i = 2; i <= sqrt(n); i++) {
    while (n % i == 0) {
      factors.insert(i);
      n /= i;
    }
  }
  if (n > 1)
    factors.insert(n);
  return factors;
}

void dfs(int i, set<int> &vis, vector<vector<int>> &adj) {
  vis.insert(i);
  for (int node : adj[i]) {
    if (vis.find(node) == vis.end())
      dfs(node, vis, adj);
  }
}

bool canTraverseAllPairs(vector<int> &nums) {
  int n = nums.size();
  vector<vector<int>> adj(n);

  unordered_map<int, int> lastindex;

  for (int i = 0; i < nums.size(); i++) {
    unordered_set<int> primefactors = uniqueprimefactors(nums[i]);

    for (int factor : primefactors) {
      if (lastindex.find(factor) != lastindex.end()) {
        int previndex = lastindex[factor];
        adj[previndex].push_back(i);
        adj[i].push_back(previndex);
      }
      lastindex[factor] = i;
    }
  }
  set<int> vis;
  dfs(0, vis, adj);
  return vis.size() == n;
}

int main() {
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
    cin >> nums[i];
  cout << canTraverseAllPairs(nums) << "\n";
  return 0;
}
