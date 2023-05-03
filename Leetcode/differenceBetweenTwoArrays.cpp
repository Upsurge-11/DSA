#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
{
  set<int> n1(nums1.begin(), nums1.end()), n2(nums2.begin(), nums2.end());
  vector<int> ans1, ans2;
  for (int i = 0; i < nums1.size(); i++)
  {
    if (n2.find(nums1[i]) == n2.end())
    {
      ans1.push_back(nums1[i]);
      n2.insert(nums1[i]);
    }
  }

  for (int i = 0; i < nums2.size(); i++)
  {
    if (n1.find(nums2[i]) == n1.end())
    {
      ans2.push_back(nums2[i]);
      n1.insert(nums2[i]);
    }
  }

  return {ans1, ans2};
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

  vector<vector<int>> ans = findDifference(nums1, nums2);

  for (int i = 0; i < ans.size(); i++)
  {
    for (int j = 0; j < ans[i].size(); j++)
      cout << ans[i][j] << " ";
    cout << "\n";
  }

  return 0;
}