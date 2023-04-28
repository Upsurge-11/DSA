#include <bits/stdc++.h>

using namespace std;

int func(vector<int> &points, vector<int> &dp, int ind)
{
  if (ind == 0)
    return 0;
  if (dp[ind] != -1)
    return dp[ind];
  int left = func(points, dp, ind - 1) + abs(points[ind - 1] - points[ind]);
  int right = INT_MAX;
  if (ind > 1)
    right = func(points, dp, ind - 2) + abs(points[ind - 2] - points[ind]);
  return dp[ind] = min(left, right);
}

int frogJump(vector<int> &points)
{
  vector<int> dp(points.size(), -1);
  return func(points, dp, points.size() - 1);
}

int main()
{
  int n;
  cin >> n;
  vector<int> points(n);
  for (int i = 0; i < n; i++)
    cin >> points[i];
  cout << frogJump(points) << "\n";

  return 0;
}