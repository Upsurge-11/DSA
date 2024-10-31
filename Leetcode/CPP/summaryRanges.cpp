#include <bits/stdc++.h>

using namespace std;

vector<string> summaryRanges(vector<int> &nums) {
  vector<string> ans;
  int n = nums.size();
  if (n == 0)
    return ans;
  int start = nums[0], end = nums[0];
  for (int i = 1; i < n; i++) {
    if (nums[i] == end + 1) {
      end = nums[i];
    } else {
      if (start == end) {
        ans.push_back(to_string(start));
      } else {
        ans.push_back(to_string(start) + "->" + to_string(end));
      }
      start = nums[i];
      end = nums[i];
    }
  }
  if (start == end) {
    ans.push_back(to_string(start));
  } else {
    ans.push_back(to_string(start) + "->" + to_string(end));
  }
  return ans;
}

int main() {
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
    cin >> nums[i];
  vector<string> ans = summaryRanges(nums);
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i] << " ";
  cout << "\n";

  return 0;
}
