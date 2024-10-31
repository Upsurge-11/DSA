#include <bits/stdc++.h>

using namespace std;

int findDuplicate(vector<int> &nums) {
  int n = nums.size();
  vector<int> freq(n, 0);
  for (int i = 0; i < n; i++) {
    freq[nums[i] - 1]++;
    if (freq[nums[i] - 1] > 1) {
      return nums[i];
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
  cout << findDuplicate(nums) << "\n";
  return 0;
}
