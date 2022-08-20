#include <bits/stdc++.h>

using namespace std;

void nextPermutaion(vector<int> &nums)
{
}

int main()
{
  int n;
  cin >> n;
  vector<int> nums(n);
  for (auto &x : nums)
  {
    cin >> x;
  }
  nextPermutaion(nums);
  for (auto &x : nums)
  {
    cout << x << " ";
  }
  return 0;
}