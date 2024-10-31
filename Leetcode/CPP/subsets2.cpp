#include <bits/stdc++.h>

using namespace std;

void util(int index, vector<int> &nums, vector<int> &temp, vector<vector<int>> &ans)
{
  ans.push_back(temp);
  for (int i = index; i < nums.size(); i++)
  {
    if (i != index && nums[i] == nums[i - 1])
      continue;
    temp.push_back(nums[i]);
    util(i + 1, nums, temp, ans);
    temp.pop_back();
  }
}

vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
  vector<int> temp;
  vector<vector<int>> ans;
  sort(nums.begin(), nums.end());
  util(0, nums, temp, ans);

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

  vector<vector<int>> ans = subsetsWithDup(nums);

  for (int i = 0; i < ans.size(); i++)
  {
    for (int j = 0; j < ans[i].size(); j++)
    {
      cout << ans[i][j] << " ";
    }
    cout << "\n";
  }

  return 0;
}