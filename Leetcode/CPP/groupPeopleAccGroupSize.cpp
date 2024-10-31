#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> groupThePeople(vector<int> &groupSizes)
{
  vector<vector<int>> ans;
  unordered_map<int, vector<int>> mp;
  for (int i = 0; i < groupSizes.size(); i++)
  {
    mp[groupSizes[i]].push_back(i);
    if (mp[groupSizes[i]].size() == groupSizes[i])
    {
      ans.push_back(mp[groupSizes[i]]);
      mp[groupSizes[i]].clear();
    }
  }
  return ans;
}

int main()
{
  int n;
  cin >> n;
  vector<int> groupSizes(n);
  for (int i = 0; i < n; i++)
    cin >> groupSizes[i];
  vector<vector<int>> res = groupThePeople(groupSizes);
  for (int i = 0; i < res.size(); i++)
  {
    for (int j = 0; j < res[i].size(); j++)
      cout << res[i][j] << " ";
    cout << "\n";
  }
  return 0;
}