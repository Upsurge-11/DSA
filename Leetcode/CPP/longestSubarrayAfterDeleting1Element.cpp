#include <bits/stdc++.h>

using namespace std;

int longestSubarray(vector<int> &nums) {
  int n = nums.size();
  int left = 0, right = 0, ans = 0, count = 0;
  while (right < n) {
    if (nums[right] == 0)
      count++;
    while (count > 1) {
      if (nums[left] == 0)
        count--;
      left++;
    }
    ans = max(ans, right - left);
    right++;
  }
  return ans;
}

int main() {
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
    cin >> nums[i];
  cout << longestSubarray(nums) << "\n";
  return 0;
}
