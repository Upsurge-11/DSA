#include <bits/stdc++.h>

using namespace std;

int func(int i, int j, string &s, vector<vector<int>> &dp)
{
  if (i == j)
    return 1;
  if (dp[i][j] != -1)
    return dp[i][j];
  int minTurns = INT_MAX;
  for (int k = i; k < j; k++)
    minTurns = min(minTurns, func(i, k, s, dp) + func(k + 1, j, s, dp));
  return dp[i][j] = (s[i] == s[j]) ? minTurns - 1 : minTurns;
}

int strangePrinter(string s)
{
  s.erase(unique(s.begin(), s.end()), s.end());
  int n = s.length();
  vector<vector<int>> dp(n, vector<int>(n, -1));
  return func(0, n - 1, s, dp);
}

int main()
{
  string s;
  cin >> s;
  cout << strangePrinter(s) << "\n";
  return 0;
}