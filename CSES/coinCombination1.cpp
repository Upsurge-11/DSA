#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, x;
  cin >> n >> x;
  vector<int> coins(n);
  for (int i = 0; i < n; i++)
    cin >> coins[i];
  vector<int> dp(x + 1, 0);
  dp[0] = 1;
  for (int i = 1; i <= x; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (i - coins[j] >= 0)
        dp[i] = (dp[i] + dp[i - coins[j]]) % 1000000007;
    }
  }
  cout << dp[x] << "\n";

  return 0;
}