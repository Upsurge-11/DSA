#include <bits/stdc++.h>

using namespace std;

int search(vector<int> &nums, int target) {
  int l = 0, r = nums.size() - 1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (nums[mid] == target)
      return mid;
    if (nums[l] <= nums[mid]) {
      if (target >= nums[l] & target <= nums[mid])
        r = mid - 1;
      else
        l = mid + 1;
    } else {
      if (target >= nums[mid] && target <= nums[r])
        l = mid + 1;
      else
        r = mid - 1;
    }
  }
  return -1;
}

int main() {
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
    cin >> nums[i];
  int target;
  cin >> target;
  cout << search(nums, target) << "\n";
  return 0;
}
