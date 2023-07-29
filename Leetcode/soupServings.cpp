#include <bits/stdc++.h>

using namespace std;

double func(double a, double b, vector<vector<double>> &dp)
{
  if (a <= 0 && b <= 0)
    return 0.5;
  if (a <= 0)
    return 1.0;
  if (b <= 0)
    return 0.0;
  if (dp[a][b] != -1)
    return dp[a][b];
  return dp[a][b] = 0.25 * (func(a - 4, b, dp) + func(a - 3, b - 1, dp) + func(a - 2, b - 2, dp) + func(a - 1, b - 3, dp));
}

double soupServings(int n)
{
  if (n > 4800)
    return 1.0;
  vector<vector<double>> dp(200, vector<double>(200, -1));
  return func(ceil(n / 25.0), ceil(n / 25.0), dp);
}

int main()
{
  int n;
  cin >> n;
  cout << soupServings(n) << "\n";
  return 0;
}