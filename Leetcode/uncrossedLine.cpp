#include <bits/stdc++.h>

using namespace std;

int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2)
{
  int n = nums1.size();
  int m = nums2.size();
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      if (nums1[i - 1] == nums2[j - 1])
        dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
    }
  }
  return dp[n][m];
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> nums1(n), nums2(m);
  for (int i = 0; i < n; i++)
    cin >> nums1[i];
  for (int i = 0; i < m; i++)
    cin >> nums2[i];
  cout << maxUncrossedLines(nums1, nums2) << "\n";

  return 0;
}