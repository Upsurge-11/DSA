#include <bits/stdc++.h>

using namespace std;

int findMin(vector<int> &nums) {
  int n = nums.size();
  int l = 0, r = n - 1, ans = INT_MAX;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (nums[l] <= nums[mid]) {
      ans = min(ans, nums[l]);
      l = mid + 1;
    } else {
      ans = min(ans, nums[mid]);
      r = mid - 1;
    }
  }
  return ans;
}

int main() {
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; ++i)
    cin >> nums[i];
  cout << findMin(nums) << "\n";
  return 0;
}
