#include <bits/stdc++.h>

using namespace std;

bool func(int i, string &s, vector<int> &dp, map<string, int> &m)
{
  if (i == s.size())
    return true;
  if (dp[i] != -1)
    return dp[i];
  bool ans = false;
  string a = "";
  for (int k = i; k < s.size(); k++)
  {
    a += s[k];
    if (m[a])
      ans |= func(k + 1, s, dp, m);
  }
  return dp[i] = ans;
}

bool wordBreak(string s, vector<string> &w)
{
  map<string, int> m;
  for (auto i : w)
    m[i]++;
  vector<int> dp(s.size(), -1);
  return func(0, s, dp, m);
}

int main()
{
  string s;
  cin >> s;
  int n;
  cin >> n;
  vector<string> w(n);
  for (int i = 0; i < n; i++)
    cin >> w[i];
  cout << wordBreak(s, w) << "\n";
  return 0;
}