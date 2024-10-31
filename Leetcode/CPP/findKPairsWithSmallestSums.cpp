#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2,
                                   int k) {
  priority_queue<pair<int, pair<int, int>>> pq;
  int n = nums1.size();
  int m = nums2.size();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int sum = nums1[i] + nums2[j];
      if (pq.size() < k)
        pq.push({sum, {nums1[i], nums2[j]}});
      else if (sum < pq.top().first) {
        pq.pop();
        pq.push({sum, {nums1[i], nums2[j]}});
      } else
        break;
    }
  }
  vector<vector<int>> ans;
  while (!pq.empty()) {
    ans.push_back({pq.top().second.first, pq.top().second.second});
    pq.pop();
  }
  return ans;
}

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> nums1(n), nums2(m);
  for (int i = 0; i < n; i++)
    cin >> nums1[i];
  for (int i = 0; i < m; i++)
    cin >> nums2[i];
  vector<vector<int>> ans = kSmallestPairs(nums1, nums2, k);
  for (int i = 0; i < ans.size(); i++) {
    for (int j = 0; j < ans[i].size(); j++)
      cout << ans[i][j] << " ";
    cout << "\n";
  }
  return 0;
}
