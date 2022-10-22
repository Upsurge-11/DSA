#include <bits/stdc++.h>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
  vector<int> result;
  for (int i = 0; i < nums.size(); i++)
  {
    for (int j = i + 1; j < nums.size(); j++)
    {
      if (nums[i] + nums[j] == target)
      {
        result.push_back(i);
        result.push_back(j);
        return result;
      }
    }
  }
  return result;
}

int main()
{
  int n, target;
  cin >> n >> target;
  vector<int> nums(n);
  for (int i = 0; i < nums.size(); i++)
  {
    cin >> nums[i];
  }
  vector<int> ans = twoSum(nums, target);

  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << " ";
  }
  cout << "\n";

  return 0;
}