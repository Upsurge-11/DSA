#include <bits/stdc++.h>

using namespace std;

bool exist(vector<int> &nums, int ele)
{
  for (int i = 0; i < nums.size(); i++)
  {
    if (nums[i] == ele)
      return true;
  }
  return false;
}

int maximalNetworkRank(int n, vector<vector<int>> &roads)
{
  vector<int> adj[n];
  for (int i = 0; i < roads.size(); i++)
  {
    adj[roads[i][0]].push_back(roads[i][1]);
    adj[roads[i][1]].push_back(roads[i][0]);
  }
  int maxRank = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      int networkRank = adj[i].size() + adj[j].size();
      if (exist(adj[i], j))
        networkRank--;
      maxRank = max(maxRank, networkRank);
    }
  }
  return maxRank;
}

int main()
{
  int n, x;
  cin >> n >> x;
  vector<vector<int>> roads(x, vector<int>(2));
  for (int i = 0; i < x; i++)
    cin >> roads[i][0] >> roads[i][1];
  cout << maximalNetworkRank(n, roads) << "\n";
  return 0;
}