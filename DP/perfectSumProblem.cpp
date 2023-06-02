#include <bits/stdc++.h>

using namespace std;

int solve(int arr[], int n, int sum, int i, vector<vector<int>> &dp)
{
  int mod = 1e9 + 7;
  if (sum == 0)
    return 1;
  if (i >= n)
    return 0;
  if (sum < 0)
    return 0;
  if (dp[i][sum] != -1)
    return dp[i][sum] % mod;
  return dp[i][sum] = ((solve(arr, n, sum - arr[i], i + 1, dp) % mod) + (solve(arr, n, sum, i + 1, dp) % mod)) % mod;
}

int perfectSum(int arr[], int n, int sum)
{
  vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
  return solve(arr, n, sum, 0, dp);
}

int main()
{
  int n, sum;
  cin >> n >> sum;
  int arr[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  cout << perfectSum(arr, n, sum) << "\n";

  return 0;
}
