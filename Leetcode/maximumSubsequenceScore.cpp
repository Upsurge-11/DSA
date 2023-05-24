#include <bits/stdc++.h>

using namespace std;

long long maxScore(vector<int> &nums1, vector<int> &nums2, int k)
{
  int n = nums1.size();
  vector<pair<int, int>> pairs(n);
  for (int i = 0; i < n; i++)
    pairs.push_back({nums2[i], nums1[i]});
  sort(pairs.rbegin(), pairs.rend());
  priority_queue<int, vector<int>, greater<int>> pq;
  long long ans = 0, totalSum = 0;
  for (auto pair : pairs)
  {
    pq.push(pair.second);
    totalSum += pair.second;
    if (pq.size() > k)
    {
      totalSum -= pq.top();
      pq.pop();
    }
    if (pq.size() == k)
      ans = max(ans, totalSum * pair.first);
  }
  return ans;
}

int main()
{
  int n, k;
  cin >> n >> k;
  vector<int> nums1(n), nums2(n);
  for (int i = 0; i < n; i++)
    cin >> nums1[i] >> nums2[i];
  cout << maxScore(nums1, nums2, k);
  return 0;
}