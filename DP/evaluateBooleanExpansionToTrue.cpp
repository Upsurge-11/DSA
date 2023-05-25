#include <bits/stdc++.h>

using namespace std;

int func(int i, int j, bool isTrue, string &exp, vector<vector<vector<int>>> &dp)
{
  if (i > j)
    return 0;
  if (i == j)
  {
    if (isTrue == true)
      return exp[i] == 'T';
    else
      return exp[i] == 'F';
      
  }
  if (dp[i][j][isTrue] != -1)
    return dp[i][j][isTrue];
  int ans = 0;
  for (int ind = i + 1; ind <= j - 1; ind += 2)
  {
    int lt = func(i, ind - 1, true, exp, dp);
    int lf = func(i, ind - 1, false, exp, dp);
    int rt = func(ind + 1, j, true, exp, dp);
    int rf = func(ind + 1, j, false, exp, dp);
    if (exp[ind] == '&')
    {
      if (isTrue)
        ans += (lt * rt);
      else
        ans += (lf * rt) + (lt * rf) + (lf * rf);
    }
    else if (exp[ind] == '|')
    {
      if (isTrue)
        ans += (lf * rt) + (lt * rf) + (lt * rt);
      else
        ans += (lf * rf);
    }
    else if (exp[ind] == '^')
    {
      if (isTrue)
        ans += (lf * rt) + (lt * rf);
      else
        ans += (lf * rf) + (lt * rt);
    }
  }
  return dp[i][j][isTrue] = ans;
}

int evaluateExp(string &exp)
{
  vector<vector<vector<int>>> dp(exp.size(), vector<vector<int>>(exp.size(), vector<int>(2, -1)));
  return func(0, exp.size() - 1, true, exp, dp);
}

int main()
{
  string exp;
  cin >> exp;
  cout << evaluateExp(exp) << "\n";
  return 0;
}