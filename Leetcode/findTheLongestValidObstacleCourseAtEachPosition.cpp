#include <bits/stdc++.h>

using namespace std;

vector<int> longestObstacleCourseAtEachPosition(vector<int> &obstacles)
{
  vector<int> ans;
  vector<int> dp;
  for (int i = 0; i < obstacles.size(); i++)
  {
    int idx = upper_bound(dp.begin(), dp.end(), obstacles[i]) - dp.begin();
    if (idx == dp.size())
      dp.push_back(obstacles[i]);
    else
      dp[idx] = obstacles[i];
    ans.push_back(idx + 1);
  }
  return ans;
}

int main()
{
  int n;
  cin >> n;
  vector<int> obstacles(n);
  for (int i = 0; i < n; i++)
    cin >> obstacles[i];
  vector<int> ans = longestObstacleCourseAtEachPosition(obstacles);
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i] << " ";
  cout << "\n";

  return 0;
}