#include <bits/stdc++.h>

using namespace std;

int lcs(string &s1, string &s2, int n, int m, vector<vector<int>> &dp)
{
  if (n == 0 || m == 0)
    return 0;
  if (dp[n][m] != -1)
    return dp[n][m];
  if (s1[n - 1] == s2[m - 1])
    return dp[n][m] = lcs(s1, s2, n - 1, m - 1, dp) + s1[n - 1];
  else
  {
    int lcs1 = lcs(s1, s2, n - 1, m, dp);
    int lcs2 = lcs(s1, s2, n, m - 1, dp);
    return dp[n][m] = max(lcs(s1, s2, n - 1, m, dp), lcs(s1, s2, n, m - 1, dp));
  }
}

int minimumDeleteSum(string s1, string s2)
{
  vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, -1));
  int lowestCommonSubsequence = lcs(s1, s2, s1.size(), s2.size(), dp);
  int sum = 0;
  for (int i = 0; i < s1.size(); i++)
    sum += s1[i];
  for (int i = 0; i < s2.size(); i++)
    sum += s2[i];
  return sum - (2 * lowestCommonSubsequence);
}

int main()
{
  string s1, s2;
  cin >> s1 >> s2;
  cout << minimumDeleteSum(s1, s2) << "\n";
  return 0;
}