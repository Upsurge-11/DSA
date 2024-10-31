#include <bits/stdc++.h>

using namespace std;

bool func(int i, int j, string &s, string &p, vector<vector<int>> &dp)
{
  if (i < 0 && j < 0)
    return true;
  if (j < 0 && i >= 0)
    return false;
  if (i < 0 && j >= 0)
  {
    for (int k = 0; k <= j; k++)
      if (p[k] != '*')
        return false;
    return true;
  }
  if (dp[i][j] != -1)
    return dp[i][j];
  if (s[i] == p[j] || p[j] == '?')
    return dp[i][j] = func(i - 1, j - 1, s, p, dp);
  if (p[j] == '*')
    return dp[i][j] = func(i, j - 1, s, p, dp) || func(i - 1, j, s, p, dp);
  return false;
}

bool isMatch(string s, string p)
{
  vector<vector<int>> dp(s.size(), vector<int>(p.size(), -1));
  return func(s.size() - 1, p.size() - 1, s, p, dp);
}

int main()
{
  string s, p;
  cin >> s >> p;
  cout << isMatch(s, p) << "\n";

  return 0;
}