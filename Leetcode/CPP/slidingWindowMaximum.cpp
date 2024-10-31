#include <bits/stdc++.h>

using namespace std;

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
  vector<int> ans;
  deque<int> dq;
  for (int i = 0; i < nums.size(); i++)
  {
    while (!dq.empty() && dq.front() < i - k + 1)
      dq.pop_front();
    while (!dq.empty() && nums[dq.back()] < nums[i])
      dq.pop_back();
    dq.push_back(i);
    if (i >= k - 1)
      ans.push_back(nums[dq.front()]);
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
  vector<int> ans = maxSlidingWindow(nums, k);
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i] << " ";
  cout << "\n";
  return 0;
}