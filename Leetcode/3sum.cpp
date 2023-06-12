#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> threeSum(vector<int> &nums) {
  int target = 0;
  sort(nums.begin(), nums.end());
  set<vector<int>> s;
  vector<vector<int>> ans;
  for (int i = 0; i < nums.size(); i++) {
    int j = i + 1;
    int k = nums.size() - 1;
    while (j < k) {
      int sum = nums[i] + nums[j] + nums[k];
      if (sum == target) {
        s.insert({nums[i], nums[j], nums[k]});
        j++;
        k--;
      } else if (sum < target) {
        j++;
      } else {
        k--;
      }
    }
  }
  for (auto triplets : s)
    ans.push_back(triplets);
  return ans;
}

int main() {
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
    cin >> nums[i];
  vector<vector<int>> ans = threeSum(nums);
  for (int i = 0; i < ans.size(); i++) {
    for (int j = 0; j < ans[i].size(); j++)
      cout << ans[i][j] << " ";
    cout << "\n";
  }

  return 0;
}
