#include <bits/stdc++.h>

using namespace std;

int findLongestChain(vector<vector<int>> &pairs)
{
  sort(pairs.begin(), pairs.end());
  vector<int> dp(pairs.size(), 1);
  int ans = 1;
  for (int i = 1; i < pairs.size(); i++)
  {
    for (int j = 0; j < i; j++)
    {
      if (pairs[i][0] > pairs[j][1])
        dp[i] = max(dp[i], dp[j] + 1);
    }
    ans = max(ans, dp[i]);
  }
  return ans;
}

int main()
{
  int n;
  cin >> n;
  vector<vector<int>> pairs(n, vector<int>(2));
  for (int i = 0; i < n; i++)
    cin >> pairs[i][0] >> pairs[i][1];
  cout << findLongestChain(pairs) << "\n";
  return 0;
}