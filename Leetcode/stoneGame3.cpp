#include <bits/stdc++.h>

using namespace std;

int func(int ind, int n, vector<int> &stoneValue, vector<int> &dp)
{
  if (ind == n)
    return 0;
  if (dp[ind] != -1)
    return dp[ind];
  int ans = stoneValue[ind] - func(ind + 1, n, stoneValue, dp);
  if (ind + 2 <= n)
    ans = max(ans, stoneValue[ind] + stoneValue[ind + 1] - func(ind + 2, n, stoneValue, dp));
  if (ind + 3 <= n)
    ans = max(ans, stoneValue[ind] + stoneValue[ind + 1] + stoneValue[ind + 2] - func(ind + 3, n, stoneValue, dp));
  return dp[ind] = ans;
}

string stoneGameIII(vector<int> &stoneValue)
{
  vector<int> dp(stoneValue.size(), -1);
  int res = func(0, stoneValue.size(), stoneValue, dp);
  if (res > 0)
    return "Alice";
  else if (res < 0)
    return "Bob";
  else
    return "Tie";
}

int main()
{
  int n;
  cin >> n;
  vector<int> stoneValue(n);
  for (int i = 0; i < n; i++)
    cin >> stoneValue[i];
  cout << stoneGameIII(stoneValue) << "\n";
  return 0;
}
