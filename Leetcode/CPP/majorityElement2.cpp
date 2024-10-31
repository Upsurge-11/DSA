#include <bits/stdc++.h>

using namespace std;

vector<int> majorityElement(vector<int> &nums) {
  int times = nums.size();
  times /= 3;
  map<int, int> m;
  vector<int> res;
  for (int i = 0; i < nums.size(); i++) {
    if (m[nums[i]] == -1) {
      continue;
    }
    if (m.find(nums[i]) != m.end()) {
      m[nums[i]]++;
    } else {
      m[nums[i]] = 1;
    }
    if (m[nums[i]] > times) {
      res.push_back(nums[i]);
      m[nums[i]] = -1;
    }
  }
  return res;
}

int main() {
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
    cin >> nums[i];
  vector<int> res = majorityElement(nums);
  for (int i = 0; i < res.size(); i++)
    cout << res[i] << " ";
  cout << "\n";
  return 0;
}
