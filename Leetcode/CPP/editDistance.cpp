#include <bits/stdc++.h>

using namespace std;

int func(vector<vector<int>> &dp, string s1, string s2, int i, int j)
{
  if (i == 0)
    return j;
  if (j == 0)
    return i;
  if (dp[i][j] != -1)
    return dp[i][j];
  if (s1[i - 1] == s2[j - 1])
    return dp[i][j] = func(dp, s1, s2, i - 1, j - 1);
  int ins = 1 + func(dp, s1, s2, i, j - 1);
  int del = 1 + func(dp, s1, s2, i - 1, j);
  int rep = 1 + func(dp, s1, s2, i - 1, j - 1);
  return dp[i][j] = min(ins, min(del, rep));
}

int minDistance(string word1, string word2)
{
  int n = word1.length(), m = word2.length();
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
  return func(dp, word1, word2, n, m);
}

int main()
{
  string word1, word2;
  cin >> word1 >> word2;
  cout << minDistance(word1, word2) << "\n";

  return 0;
}