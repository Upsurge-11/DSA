#include <bits/stdc++.h>

using namespace std;

int lcs(int ind1, int ind2, string s1, string s2, vector<vector<int>> &dp)
{
  if (ind1 < 0 || ind2 < 0)
    return 0;
  if (dp[ind1][ind2] != -1)
    return dp[ind1][ind2];
  if (s1[ind1] == s2[ind2])
    return dp[ind1][ind2] = (1 + lcs(ind1 - 1, ind2 - 1, s1, s2, dp));
  else
    return dp[ind1][ind2] = max(lcs(ind1, ind2 - 1, s1, s2, dp), lcs(ind1 - 1, ind2, s1, s2, dp));
}

int main()
{
  string s1, s2;
  cin >> s1 >> s2;
  vector<vector<int>> dp(s1.size(), vector<int>(s2.size(), -1));
  cout << lcs(s1.size() - 1, s2.size() - 1, s1, s2, dp) << "\n";

  return 0;
}