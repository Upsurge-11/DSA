#include <bits/stdc++.h>

using namespace std;

bool cmp(vector<int> &a, vector<int> &b)
{
  return a[1] < b[1];
}

int eraseOverlapIntervals(vector<vector<int>> &intervals)
{
  sort(intervals.begin(), intervals.end(), cmp);
  int prev = 0;
  int count = 1;
  for (int i = 1; i < intervals.size(); i++)
  {
    if (intervals[i][0] >= intervals[prev][1])
    {
      prev = i;
      count++;
    }
  }
  return intervals.size() - count;
}

int main()
{
  int n;
  cin >> n;
  vector<vector<int>> intervals(n, vector<int>(2));
  for (int i = 0; i < n; i++)
    cin >> intervals[i][0] >> intervals[i][1];
  cout << eraseOverlapIntervals(intervals) << "\n";
  return 0;
}