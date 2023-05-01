#include <bits/stdc++.h>

using namespace std;

int func(int day, int ind, vector<vector<int>> &points, vector<vector<int>> &dp)
{
  if (dp[day][ind] != -1)
    return dp[day][ind];
  if (day == 0)
  {
    int maxi = 0;
    for (int i = 0; i < 3; i++)
    {
      if (i != ind)
        maxi = max(maxi, points[day][i]);
    }
    return maxi;
  }
  int ans = 0;
  for (int i = 0; i < 3; i++)
  {
    if (i != ind)
      ans = max(ans, points[day][i] + func(day - 1, i, points, dp));
  }
  return dp[day][ind] = ans;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
  vector<vector<int>> dp(n, vector<int>(4, -1));
  return func(n - 1, 3, points, dp);
}

int main()
{
  int n;
  cin >> n;
  vector<vector<int>> points(n, vector<int>(3));
  for (int i = 0; i < n; i++)
    cin >> points[i][0] >> points[i][1] >> points[i][2];
  cout << ninjaTraining(n, points) << "\n";

  return 0;
}