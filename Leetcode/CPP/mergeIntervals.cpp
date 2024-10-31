#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals) {
  vector<vector<int>> ans;
  sort(intervals.begin(), intervals.end());
  int i = 0;
  while (i < intervals.size()) {
    int start = intervals[i][0];
    int end = intervals[i][1];
    while (i < intervals.size() - 1 && end >= intervals[i + 1][0]) {
      end = max(end, intervals[i + 1][1]);
      i++;
    }
    ans.push_back({start, end});
    i++;
  }
  return ans;
}

int main() {
  int n;
  cin >> n;
  vector<vector<int>> intervals(n, vector<int>(2));
  for (int i = 0; i < n; i++)
    cin >> intervals[i][0] >> intervals[i][1];
  vector<vector<int>> ans = merge(intervals);
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i][0] << " " << ans[i][1] << endl;
  return 0;
}
