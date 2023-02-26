#include <bits/stdc++.h>

using namespace std;

int solve(vector<vector<int>> &dp, string s1, string s2, int i1, int i2)
{
  if (i1 == 0)
    return i2;
  if (i2 == 0)
    return i1;
  if (dp[i1][i2] != -1)
    return dp[i1][i2];
  if (s1[i1 - 1] == s2[i2 - 1])
    return dp[i1][i2] = solve(dp, s1, s2, i1 - 1, i2 - 1);
  int ins = 1 + solve(dp, s1, s2, i1, i2 - 1);
  int del = 1 + solve(dp, s1, s2, i1 - 1, i2);
  int rep = 1 + solve(dp, s1, s2, i1 - 1, i2 - 1);
  return dp[i1][i2] = min(ins, min(del, rep));
}

int minDistance(string word1, string word2)
{
  int n = word1.length(), m = word2.length();
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
  return solve(dp, word1, word2, n, m);
}

int main()
{
  string word1, word2;
  cin >> word1 >> word2;
  cout << minDistance(word1, word2) << "\n";

  return 0;
}