#include <bits/stdc++.h>

using namespace std;

vector<int> shuffle(vector<int> &nums, int n)
{
  vector<int> res, half1, half2;
  for (int i = 0; i < n; i++)
  {
    half1.push_back(nums[i]);
    half2.push_back(nums[n + i]);
  }
  for (int i = 0; i < n; i++)
  {
    res.push_back(half1[i]);
    res.push_back(half2[i]);
  }
  return res;
}

int main()
{
  int n;
  cin >> n;
  vector<int> nums(2 * n);
  for (int i = 0; i < 2 * n; i++)
    cin >> nums[i];

  vector<int> ans = shuffle(nums, n);

  for (int i = 0; i < ans.size(); i++)
    cout << ans[i] << " ";
  cout << "\n";

  return 0;
}