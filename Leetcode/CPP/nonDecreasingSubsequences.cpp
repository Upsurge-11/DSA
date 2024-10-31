#include <bits/stdc++.h>

using namespace std;

void util(vector<int> &nums, vector<vector<int>> &ans, vector<int> &temp, int ind)
{
  if (ind == nums.size())
  {
    if (temp.size() >= 2)
      ans.push_back(temp);
    return;
  }

  if (temp.size() == 0 || nums[ind] >= temp[temp.size() - 1])
  {
    temp.push_back(nums[ind]);
    util(nums, ans, temp, ind + 1);
    temp.pop_back();
  }

  if (temp.size() == 0 || nums[ind] != temp[temp.size() - 1])
    util(nums, ans, temp, ind + 1);
}

vector<vector<int>> findSubsequences(vector<int> &nums)
{
  vector<vector<int>> ans;
  vector<int> temp;
  util(nums, ans, temp, 0);
  return ans;
}

int main()
{
  int n;
  cin >> n;
  vector<int> nums(n);

  for (int i = 0; i < n; i++)
    cin >> nums[i];

  vector<vector<int>> ans = findSubsequences(nums);

  for (int i = 0; i < ans.size(); i++)
  {
    for (int j = 0; j < ans[i].size(); j++)
      cout << ans[i][j] << " ";
    cout << "\n";
  }

  return 0;
}