#include <bits/stdc++.h>

using namespace std;

bool increasingTriplet(vector<int> &nums)
{
  int n = nums.size();
  if (n < 3)
    return false;
  int first = INT_MAX, second = INT_MAX;
  for (int i = 0; i < n; i++)
  {
    if (nums[i] <= first)
      first = nums[i];
    else if (nums[i] <= second)
      second = nums[i];
    else
      return true;
  }
  return false;
}

int main()
{
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
  {
    cin >> v[i];
  }

  if (increasingTriplet(v))
  {
    cout << "true\n";
  }
  else
  {
    cout << "false\n";
  }

  return 0;
}