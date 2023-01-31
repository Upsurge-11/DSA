#include <bits/stdc++.h>

using namespace std;

int bestTeamScore(vector<int> &scores, vector<int> &ages)
{
  int n = scores.size();
  int dp[n], ans = 0;
  vector<pair<int, int>> players;
  for (int i = 0; i < n; i++)
    players.push_back({ages[i], scores[i]});
  sort(players.begin(), players.end());
  for (int i = 0; i < n; i++)
  {
    dp[i] = players[i].second;
    for (int j = 0; j < i; j++)
    {
      if (players[j].second <= players[i].second)
        dp[i] = max(dp[i], dp[j] + players[i].second);
    }
    ans = max(ans, dp[i]);
  }
  return ans;
}

int main()
{
  int n;
  cin >> n;
  vector<int> scores(n), ages(n);
  for (int i = 0; i < n; i++)
    cin >> scores[i] >> ages[n];

  cout << bestTeamScore(scores, ages) << "\n";

  return 0;
}