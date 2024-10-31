#include <bits/stdc++.h>

using namespace std;

vector<int> rearrangeArray(vector<int> &nums)
{
  int n = nums.size();
  vector<int> store(n);
  int start = 0, end = n - 1;
  for (int i = 0; i < n; i++)
  {
    if (nums[i] > 0)
      store[start++] = nums[i];
    else
      store[end--] = nums[i];
  }
  start = 0, end = n - 1;
  for (int i = 0; i < n; i++)
  {
    if (i % 2 == 0)
      nums[i] = store[start++];
    else
      nums[i] = store[end--];
  }
  return nums;
}

int main()
{
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }

  vector<int> ans = rearrangeArray(nums);

  for (int i = 0; i < n; i++)
  {
    cout << ans[i] << " ";
  }
  cout << "\n";

  return 0;
}