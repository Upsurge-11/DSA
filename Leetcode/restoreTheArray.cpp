#include <bits/stdc++.h>

using namespace std;

int numberOfArrays(string s, int k)
{
  int n = s.size();
  vector<long long> dp(n + 1, 0);
  dp[0] = 1;
  for (int i = 0; i < n; i++)
  {
    if (s[i] == '0')
      continue;
    long long num = 0;
    for (int j = i; j < n; j++)
    {
      num = num * 10 + (s[j] - '0');
      if (num > k)
        break;
      dp[j + 1] = (dp[j + 1] + dp[i]) % 1000000007;
    }
  }
  return dp[n];
}

int main()
{
  string s;
  cin >> s;
  int k;
  cin >> k;
  cout << numberOfArrays(s, k) << "\n";

  return 0;
}