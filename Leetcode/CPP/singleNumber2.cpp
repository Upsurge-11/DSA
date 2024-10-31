#include <bits/stdc++.h>

using namespace std;

int singleNumber(vector<int> &nums) {
  int ans = 0;
  for (int i = 0; i < 32; i++) {
    int sum = 0;
    for (int j = 0; j < nums.size(); j++) {
      if ((nums[j] >> i) & 1)
        sum++;
    }
    sum %= 3;
    if (sum)
      ans |= sum << i;
  }
  return ans;
}

int main() {
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
    cin >> nums[i];
  cout << singleNumber(nums) << "\n";

  return 0;
}
