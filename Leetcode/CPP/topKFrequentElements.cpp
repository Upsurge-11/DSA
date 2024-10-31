#include <bits/stdc++.h>

using namespace std;

vector<int> topKFrequent(vector<int> &nums, int k)
{
  priority_queue<pair<int, int>> pq;
  unordered_map<int, int> mp;
  vector<int> ans;
  for (int i = 0; i < nums.size(); i++)
    mp[nums[i]]++;
  for (auto it = mp.begin(); it != mp.end(); it++)
    pq.push({it->second, it->first});
  while (k--)
  {
    ans.push_back(pq.top().second);
    pq.pop();
  }
  return ans;
}

int main()
{
  int n, k;
  cin >> n >> k;
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
    cin >> nums[i];
  vector<int> ans = topKFrequent(nums, k);
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i] << " ";
  cout << "\n";

  return 0;
}