#include <bits/stdc++.h>

using namespace std;

long long int func(int n, int goal, int k, vector<vector<int>> &dp, int MOD)
{
  if (n == 0 && goal == 0)
    return 1;
  if (n == 0 || goal == 0)
    return 0;
  if (dp[n][goal] != -1)
    return dp[n][goal];
  long long int take = func(n - 1, goal - 1, k, dp, MOD) * n;
  long long int notTake = func(n, goal - 1, k, dp, MOD) * max(n - k, 0);
  return dp[n][goal] = (take + notTake) % MOD;
}

int numMusicPlaylists(int n, int goal, int k)
{
  int MOD = 1e9 + 7;
  vector<vector<int>> dp(n + 1, vector<int>(goal + 1, -1));
  return func(n, goal, k, dp, MOD);
}

int main()
{
  int n, goal, k;
  cin >> n >> goal >> k;
  cout << numMusicPlaylists(n, goal, k) << "\n";
  return 0;
}