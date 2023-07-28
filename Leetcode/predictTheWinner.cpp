#include <bits/stdc++.h>

using namespace std;

int func(int left, int right, int turn, vector<int> &nums)
{
  if (left > right)
    return 0;
  int ans = 0;
  if (turn % 2 == 0)
  {
    int first = nums[left] + func(left + 1, right, turn + 1, nums);
    int last = nums[right] + func(left, right - 1, turn + 1, nums);
    ans = max(first, last);
  }
  else
  {
    int first = -nums[left] + func(left + 1, right, turn + 1, nums);
    int last = -nums[right] + func(left, right - 1, turn + 1, nums);
    ans = min(first, last);
  }
  return ans;
}

bool PredictTheWinner(vector<int> &nums)
{
  return func(0, nums.size() - 1, 0, nums) >= 0;
}

int main()
{
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
    cin >> nums[i];
  cout << PredictTheWinner(nums) << "\n";

  return 0;
}