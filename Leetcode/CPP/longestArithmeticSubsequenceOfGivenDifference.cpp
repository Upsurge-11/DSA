#include <bits/stdc++.h>

using namespace std;

// int func(int ind, vector<int> &arr, int difference, int prev, vector<vector<int>> &dp)
// {
//   if (ind == arr.size())
//     return 0;
//   if (dp[ind][prev + 10001] != -1)
//     return dp[ind][prev + 10001];
//   int take = INT_MIN, nonTake = func(ind + 1, arr, difference, prev, dp);
//   if (prev == -10001 || arr[ind] - prev == difference)
//     take = func(ind + 1, arr, difference, arr[ind], dp) + 1;
//   return dp[ind][prev + 10001] = max(take, nonTake);
// }

// int longestSubsequence(vector<int> &arr, int difference)
// {
//   vector<vector<int>> dp(arr.size(), vector<int>(20002, -1));
//   return func(0, arr, difference, -10001, dp);
// }

int longestSubsequence(vector<int> &arr, int difference)
{
  unordered_map<int, int> mp;
  int ans = 0;
  for (int i : arr)
  {
    mp[i] = mp[i - difference] + 1;
    ans = max(mp[i], ans);
  }
  return ans;
}

int main()
{
  int n, difference;
  cin >> n >> difference;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  cout << longestSubsequence(arr, difference) << "\n";
  return 0;
}