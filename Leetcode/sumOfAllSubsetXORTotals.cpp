#include <bits/stdc++.h>

using namespace std;

void subset(int ind, vector<int> &nums, vector<vector<int>> &res, vector<int> &ds)
{
  if (ind == nums.size())
  {
    res.push_back(ds);
    return;
  }
  ds.push_back(nums[ind]);
  subset(ind + 1, nums, res, ds);
  ds.pop_back();
  subset(ind + 1, nums, res, ds);
}

int subsetXORSum(vector<int> &nums)
{
  vector<vector<int>> res;
  vector<int> ds;
  subset(0, nums, res, ds);
  int ans = 0;
  for (int i = 0; i < res.size(); i++)
  {
    int xorTotal = 0;
    for (int j = 0; j < res[i].size(); j++)
      xorTotal = xorTotal ^ res[i][j];
    ans += xorTotal;
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
  cout << subsetXORSum(nums) << "\n";
  return 0;
}