#include <bits/stdc++.h>

using namespace std;

int findKthLargest(vector<int> &nums, int k)
{
  priority_queue<int> pq;
  for (int i = 0; i < nums.size(); i++)
    pq.push(nums[i]);
  while (--k)
    pq.pop();
  return pq.top();
}

int main()
{
  int n, k;
  cin >> n >> k;
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
    cin >> nums[i];

  cout << findKthLargest(nums, k) << "\n";

  return 0;
}