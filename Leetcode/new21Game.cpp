#include <bits/stdc++.h>

using namespace std;

// double func(int curr, int k, int n, int maxPts, vector<double> &dp)
// {
//   if (curr >= k)
//     return curr <= n;
//   if (dp[curr] != -1.0)
//     return dp[curr];
//   double sum = 0;
//   for (int i = 1; i <= maxPts; i++)
//     sum += func(curr + i, k, n, maxPts, dp);
//   return dp[curr] = sum / maxPts;
// }

// double new21Game(int n, int k, int maxPts)
// {
//   vector<double> dp(n, -1.0);
//   return func(0, k, n, maxPts, dp);
// }

double new21Game(int n, int k, int maxPts)
{
  if (k == 0)
    return 1.0;
  if (n >= k - 1 + maxPts)
    return 1.0;
  vector<double> dp(n + 1, 0.0);
  double p = 0.0;
  double sum = 1.0;
  dp[0] = 1.0;
  for (int i = 1; i <= n; i++)
  {
    dp[i] = sum / maxPts;
    if (i < k)
      sum += dp[i];
    else
      p += dp[i];
    if (i >= maxPts)
      sum -= dp[i - maxPts];
  }
  return p;
}

int main()
{
  int n, k, maxPts;
  cin >> n >> k >> maxPts;
  cout << new21Game(n, k, maxPts) << "\n";

  return 0;
}