#include <bits/stdc++.h>

using namespace std;

void func(int ind, int n, int k, vector<int> &temp, vector<vector<int>> &ans)
{
  if (ind > n)
  {
    if (temp.size() == k)
      ans.push_back(temp);
    return;
  }
  temp.push_back(ind);
  func(ind + 1, n, k, temp, ans);
  temp.pop_back();
  func(ind + 1, n, k, temp, ans);
}

vector<vector<int>> combine(int n, int k)
{
  vector<int> temp;
  vector<vector<int>> ans;
  func(1, n, k, temp, ans);
  return ans;
}

int main()
{
  int n, k;
  cin >> n >> k;
  vector<vector<int>> ans = combine(n, k);
  for (int i = 0; i < ans.size(); i++)
  {
    for (int j = 0; j < k; j++)
      cout << ans[i][j] << " ";
    cout << "\n";
  }

  return 0;
}