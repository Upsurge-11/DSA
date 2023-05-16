#include <bits/stdc++.h>

using namespace std;

long long func(int i, vector<vector<int>> &q, vector<long long> &dp)
{
  if (i >= q.size())
    return 0;
  long long ans = 0;
  if (dp[i] != -1)
    return dp[i];
  ans = max(q[i][0] + func(i + q[i][1] + 1, q, dp), func(i + 1, q, dp));
  dp[i] = ans;
  return ans;
}

long long mostPoints(vector<vector<int>> &q)
{
  int n = q.size();
  vector<long long> dp(n, -1);
  return func(0, q, dp);
}

int main()
{
  int n;
  cin >> n;
  vector<vector<int>> q(n, vector<int>(2));
  for (int i = 0; i < n; i++)
    cin >> q[i][0] >> q[i][1];
  cout << mostPoints(q) << "\n";

  return 0;
}