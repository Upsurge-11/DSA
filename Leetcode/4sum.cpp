#include <bits/stdc++.h>

using namespace std;

void func(vector<int> &nums, int &target, int index, vector<int> &temp,
          vector<vector<int>> &ans) {
  if (temp.size() == 4) {
    if (target == 0)
      ans.push_back(temp);
    return;
  }
  for (int i = index; i < nums.size(); i++) {
    if (i > index && nums[i] == nums[i - 1])
      continue;
    temp.push_back(nums[i]);
    target -= nums[i];
    func(nums, target, i + 1, temp, ans);
    target += nums[i];
    temp.pop_back();
  }
}

vector<vector<int>> fourSum(vector<int> &nums, int target) {
  vector<int> temp;
  vector<vector<int>> ans;
  sort(nums.begin(), nums.end());
  func(nums, target, 0, temp, ans);
  return ans;
}

int main() {
  int n, target;
  cin >> n >> target;
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
    cin >> nums[i];
  vector<vector<int>> ans = fourSum(nums, target);
  for (int i = 0; i < ans.size(); i++) {
    for (int j = 0; j < ans[i].size(); j++)
      cout << ans[i][j] << " ";
    cout << "\n";
  }

  return 0;
}
