#include <bits/stdc++.h>

using namespace std;

int func(int start, int finish, int fuel, vector<int> &locations, int n,
         vector<vector<int>> &dp, int MOD) {
  if (fuel < 0)
    return 0;
  if (dp[start][fuel] != -1)
    return dp[start][fuel];
  long long ans = start == finish ? 1 : 0;
  for (int i = 0; i < n; i++) {
    if (i != start && fuel >= abs(locations[i] - locations[start]))
      ans += func(i, finish, fuel - abs(locations[i] - locations[start]),
                  locations, n, dp, MOD) %
             MOD;
  }
  return dp[start][fuel] = ans % MOD;
}

int countRoutes(vector<int> &locations, int start, int finish, int fuel) {
  int n = locations.size();
  int MOD = 1e9 + 7;
  vector<vector<int>> dp(n, vector<int>(fuel + 1, -1));
  return func(start, finish, fuel, locations, n, dp, MOD);
}

int main() {
  int n, start, finish, fuel;
  cin >> n >> start >> finish >> fuel;
  vector<int> locations(n);
  for (int i = 0; i < n; i++)
    cin >> locations[i];
  cout << countRoutes(locations, start, finish, fuel) << "\n";
  return 0;
}
