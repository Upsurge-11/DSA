#include <bits/stdc++.h>

using namespace std;

vector<int> findErrorNums(vector<int> &nums)
{
  int n = nums.size();
  vector<int> ans(2, 0);
  vector<int> freq(n, 0);
  for (int i = 0; i < n; i++)
  {
    freq[nums[i] - 1]++;
  }
  for (int i = 0; i < n; i++)
  {
    if (freq[i] == 2)
      ans[0] = i + 1;
    else if (freq[i] == 0)
      ans[1] = i + 1;
  }
  return ans;
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

  vector<int> ans = findErrorNums(nums);

  for (int i = 0; i < n; i++)
  {
    cout << ans[i] << " ";
  }
  cout << "\n";

  return 0;
}