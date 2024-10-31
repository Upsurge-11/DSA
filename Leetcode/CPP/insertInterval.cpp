#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
{
  vector<vector<int>> ans;
  int i = 0, n = intervals.size();
  while (i < n && intervals[i][1] < newInterval[0])
    ans.push_back(intervals[i++]);
  while (i < n && intervals[i][0] <= newInterval[1])
    newInterval = {min(intervals[i][0], newInterval[0]), max(intervals[i][1], newInterval[1])}, i++;
  ans.push_back(newInterval);
  while (i < n)
    ans.push_back(intervals[i++]);
  return ans;
}

int main()
{
  int n;
  cin >> n;
  vector<vector<int>> intervals(n, vector<int>(2));
  vector<int> newIntervals(1);
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < 2; j++)
      cin >> intervals[i][j];
  }

  cin >> newIntervals[0] >> newIntervals[1];

  vector<vector<int>> ans = insert(intervals, newIntervals);

  for (int i = 0; i < ans.size(); i++)
  {
    for (int j = 0; j < 2; j++)
      cout << ans[i][j] << " ";
    cout << "\n";
  }

  return 0;
}