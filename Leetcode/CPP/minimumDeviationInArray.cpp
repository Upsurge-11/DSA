#include <bits/stdc++.h>

using namespace std;

int minimumDeviation(vector<int> &nums)
{
  priority_queue<int> pq;
  int mini = INT_MAX, ans = INT_MAX;
  for (int i = 0; i < nums.size(); i++)
  {
    if (nums[i] % 2 == 1)
      nums[i] *= 2;
    pq.push(nums[i]);
    mini = min(mini, nums[i]);
  }
  while (1)
  {
    int maxi = pq.top();
    pq.pop();
    ans = min(ans, maxi - mini);
    if (maxi % 2 == 1)
      break;
    maxi /= 2;
    mini = min(mini, maxi);
    pq.push(maxi);
  }
  return ans;
}

int main()
{
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
    cin >> nums[i];
  cout << minimumDeviation(nums) << "\n";

  return 0;
}