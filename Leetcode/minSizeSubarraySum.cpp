#include <bits/stdc++.h>

using namespace std;

int minSubArrayLen(int target, vector<int> &nums) {
  int n = nums.size();
  int ans = INT_MAX;
  int sum = 0;
  int left = 0;
  for (int i = 0; i < n; i++) {
    sum += nums[i];
    while (sum >= target) {
      ans = min(ans, i + 1 - left);
      sum -= nums[left++];
    }
  }
  return (ans != INT_MAX) ? ans : 0;
}

int main() {
  int n, target;
  cin >> n >> target;
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
    cin >> nums[i];
  cout << minSubArrayLen(target, nums) << "\n";

  return 0;
}
