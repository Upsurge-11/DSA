#include <bits/stdc++.h>

using namespace std;

void util(int index, int target, vector<vector<int>> &ans, vector<int> &candidates, vector<int> &temp)
{
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
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

  vector<vector<int>> ans = combinationSum2(candidates, target);

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