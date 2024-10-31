#include <bits/stdc++.h>

using namespace std;

int func(int ind, vector<vector<int>> &events, int k, int day, vector<vector<int>> &dp)
{
  if (ind == events.size() || k == 0)
    return 0;
  if (events[ind][0] <= day)
    return func(ind + 1, events, k, day, dp);
  if (dp[ind][k] != -1)
    return dp[ind][k];
  int take = INT_MIN;
  if (day < events[ind][0])
    take = events[ind][2] + func(ind + 1, events, k - 1, events[ind][1], dp);
  int nonTake = func(ind + 1, events, k, day, dp);
  return dp[ind][k] = max(take, nonTake);
}

int maxValue(vector<vector<int>> &events, int k)
{
  sort(events.begin(), events.end());
  vector<vector<int>> dp(events.size(), vector<int>(k + 1, -1));
  return func(0, events, k, 0, dp);
}

int main()
{
  int n, k;
  cin >> n >> k;
  vector<vector<int>> events(n, vector<int>(3));
  for (int i = 0; i < n; i++)
    cin >> events[i][0] >> events[i][1] >> events[i][2];
  cout << maxValue(events, k) << "\n";
  return 0;
}