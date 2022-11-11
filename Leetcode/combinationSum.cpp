#include <bits/stdc++.h>

using namespace std;

void util(int ind, vector<vector<int>> &matrix, vector<int> arr, vector<int> &temp, int target, int sum)
{
  if (ind >= arr.size())
  {
    if (sum == target)
      matrix.push_back(temp);
    return;
  }
  sum += arr[ind];
  temp.push_back(arr[ind]);
  util(ind + 1, matrix, arr, temp, target, sum);
  temp.pop_back();
  sum -= arr[ind];
  util(ind + 1, matrix, arr, temp, target, sum);
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
  vector<vector<int>> ans;
  vector<int> temp;
  util(0, ans, candidates, temp, target, 0);
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