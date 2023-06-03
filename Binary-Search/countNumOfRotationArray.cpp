#include <bits/stdc++.h>

using namespace std;

int countRotations(vector<int> &nums) {
  int n = nums.size();
  int l = 0, r = n - 1, ans = INT_MAX, ind = 0;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (nums[l] <= nums[mid]) {
      if (nums[l] < ans) {
        ans = nums[l];
        ind = l;
      }
      l = mid + 1;
    } else {
      if (nums[mid] < ans) {
        ans = nums[l];
        ind = mid;
      }
      r = mid - 1;
    }
  }
  return ind;
}

int main() {
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
    cin >> nums[i];
  cout << countRotations(nums) << "\n";
  return 0;
}
