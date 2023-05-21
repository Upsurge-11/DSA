#include <bits/stdc++.h>

using namespace std;

int rodCutting(int ind, int length, vector<int> &cost, vector<vector<int>> &dp)
{
  if (ind == 0)
    return length * cost[0];
  if (dp[ind][length] != -1)
    return dp[ind][length];
  int nonTake = rodCutting(ind - 1, length, cost, dp);
  int take = INT_MIN;
  if (ind + 1 <= length)
    take = cost[ind] + rodCutting(ind, length - ind - 1, cost, dp);
  return dp[ind][length] = max(nonTake, take);
}

int main()
{
  int length;
  cin >> length;
  vector<int> cost(length);
  for (int i = 0; i < length; i++)
    cin >> cost[i];
  vector<vector<int>> dp(length, vector<int>(length + 1, -1));
  cout << rodCutting(length - 1, length, cost, dp) << "\n";

  return 0;
}