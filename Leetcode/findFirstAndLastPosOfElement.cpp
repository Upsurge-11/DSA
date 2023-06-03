#include <bits/stdc++.h>

using namespace std;

// int lowerBound(int n, vector<int> &v, int x) {
//   int l = 0, r = n - 1, ans = n;
//   while (l <= r) {
//     int mid = (l + r) / 2;
//     if (v[mid] >= x) {
//       ans = mid;
//       r = mid - 1;
//     } else
//       l = mid + 1;
//   }
//   return ans;
// }
//
// int upperBound(int n, vector<int> &v, int x) {
//   int l = 0, r = n - 1, ans = n;
//   while (l <= r) {
//     int mid = (l + r) / 2;
//     if (v[mid] > x) {
//       ans = mid;
//       r = mid - 1;
//     } else
//       l = mid + 1;
//   }
//   return ans;
// }

// vector<int> searchRange(vector<int> &nums, int target) {
//   int first = lowerBound(nums.size(), nums, target);
//   if (first == nums.size() || nums[first] != target)
//     return {-1, -1};
//   return {first, upperBound(nums.size(), nums, target) - 1};
// }

vector<int> searchRange(vector<int> &nums, int target) {
  int first = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
  if (first == nums.size() || nums[first] != target)
    return {-1, -1};
  int last = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
  return {first, last - 1};
}

int main() {
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
    cin >> nums[i];
  int target;
  cin >> target;
  vector<int> ans = searchRange(nums, target);
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i] << " ";
  cout << "\n";
  return 0;
}
