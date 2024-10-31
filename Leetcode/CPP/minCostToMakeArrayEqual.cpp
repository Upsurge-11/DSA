#include <bits/stdc++.h>

using namespace std;

// long long minCost(vector<int> &nums, vector<int> &cost) {
//   int n = nums.size();
//   long long ans = LLONG_MAX;
//   for (int i = 0; i < n; i++) {
//     long long temp = 0;
//     for (int j = 0; j < n; j++) {
//       if (i == j)
//         continue;
//       temp += (long long)(abs(nums[i] - nums[j])) * (long long)cost[j];
//     }
//     ans = min(ans, temp);
//   }
//   return ans;
// }

long long getCost(vector<int> &nums, vector<int> &cost, int num) {
  long long ans = 0;
  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] == num)
      continue;
    ans += (long long)(abs(nums[i] - num)) * (long long)cost[i];
  }
  return ans;
}

long long minCost(vector<int> &nums, vector<int> &cost) {
  long long ans = getCost(nums, cost, nums[0]);
  int left = nums[0], right = nums[0];
  for (int i = 1; i < nums.size(); i++) {
    left = min(nums[i], left);
    right = max(nums[i], right);
  }
  while (left < right) {
    long long mid = (left + right) / 2;
    long long cost1 = getCost(nums, cost, mid);
    long long cost2 = getCost(nums, cost, mid + 1);
    ans = min(cost1, cost2);
    if (cost1 < cost2)
      right = mid;
    else
      left = mid + 1;
  }
  return ans;
}

int main() {
  int n;
  cin >> n;
  vector<int> nums(n), cost(n);
  for (int i = 0; i < n; ++i)
    cin >> nums[i];
  for (int i = 0; i < n; ++i)
    cin >> cost[i];
  cout << minCost(nums, cost) << "\n";
  return 0;
}
