#include <bits/stdc++.h>

using namespace std;

int lcs(string s1, string s2)
{
  int n = s1.length();
  int m = s2.length();
  vector<vector<int>> dp(n + 1, vector<int>(m + 1));
  for (int i = 0; i <= n; i++)
  {
    for (int j = 0; j <= m; j++)
    {
      if (i == 0 || j == 0)
        dp[i][j] = 0;
      else if (s1[i - 1] == s2[j - 1])
        dp[i][j] = 1 + dp[i - 1][j - 1];
      else
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
  }
  return dp[n][m];
}

int longestPalindromeSubseq(string s)
{
  string s1 = s;
  reverse(s.begin(), s.end());
  string s2 = s;
  return lcs(s1, s2);
}

int main()
{
  string s;
  cin >> s;
  cout << longestPalindromeSubseq(s) << "\n";
  return 0;
}