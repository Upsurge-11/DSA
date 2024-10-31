#include <bits/stdc++.h>

using namespace std;

vector<int> getAverages(vector<int> &nums, int k)
{
  vector<int> ans(nums.size(), -1);
  if (k > nums.size() / 2)
    return ans;
  vector<long long> prefixSum(nums.size() + 1, 0);
  for (int i = 0; i < nums.size(); i++)
    prefixSum[i + 1] = prefixSum[i] + nums[i];
  for (int i = k; i < nums.size() - k; i++)
    ans[i] = (prefixSum[i + k + 1] - prefixSum[i - k]) / (2 * k + 1);
  return ans;
}

int main()
{
  int n, k;
  cin >> n >> k;
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
    cin >> nums[i];
  vector<int> ans = getAverages(nums, k);
  for (int i = 0; i < n; i++)
    cout << ans[i] << " ";
  cout << "\n";

  return 0;
}