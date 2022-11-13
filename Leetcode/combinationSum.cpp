#include <bits/stdc++.h>

using namespace std;

void util(int index, int target, vector<vector<int>> &ans, vector<int> candidates, vector<int> ds)
{
  if (index < 0 || index >= candidates.size())
  {
    if (target == 0)
    {
      ans.push_back(ds);
      return;
    }
    return;
  }
  if (target < 0)
  {
    return;
  }
  ds.push_back(candidates[index]);
  target -= candidates[index];
  util(index, target, ans, candidates, ds);
  ds.pop_back();
  target += candidates[index];
  util(index + 1, target, ans, candidates, ds);
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
  vector<vector<int>> ans;
  vector<int> temp;

  util(0, target, ans, candidates, temp);

  return ans;
}

int main()
{
  int n, target;
  cin >> n >> target;
  vector<int> candidates(n);
  for (int i = 0; i < n; i++)
  {
    cin >> candidates[i];
  }

  vector<vector<int>> ans = combinationSum(candidates, target);

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