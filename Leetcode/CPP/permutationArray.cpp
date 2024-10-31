#include <bits/stdc++.h>

using namespace std;

void util(vector<int> &temp, vector<int> &nums, vector<vector<int>> &ans, vector<int> &freq)
{
  if (temp.size() == nums.size())
  {
    ans.push_back(temp);
    return;
  }

  for (int i = 0; i < nums.size(); i++)
  {
    if (!freq[i])
    {
      temp.push_back(nums[i]);
      freq[i] = 1;
      util(temp, nums, ans, freq);
      freq[i] = 0;
      temp.pop_back();
    }
  }
}

void util(int ind, vector<int> &nums, vector<vector<int>> &ans)
{
  if (ind == nums.size())
  {
    ans.push_back(nums);
    return;
  }
  for (int i = ind; i < nums.size(); i++)
  {
    swap(nums[ind], nums[i]);
    util(ind + 1, nums, ans);
    swap(nums[ind], nums[i]);
  }
}

vector<vector<int>> permute(vector<int> &nums)
{
  vector<vector<int>> ans;
  vector<int> temp;
  int n = nums.size();
  vector<int> freq(n, 0);
  // util(temp, nums, ans, freq);
  util(0, nums, ans);

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

  vector<vector<int>> ans = permute(nums);

  for (auto &x : ans)
  {
    for (auto &y : x)
    {
      cout << y << " ";
    }
    cout << "\n";
  }

  return 0;
}