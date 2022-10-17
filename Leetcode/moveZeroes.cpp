#include <bits/stdc++.h>

using namespace std;

void moveZeroes(vector<int> &nums)
{
  int n = nums.size();
  int i = 0;
  for (int j = 0; j < n; j++)
  {
    if (nums[j] != 0)
    {
      nums[i] = nums[j];
      i++;
    }
  }
  for (int j = i; j < n; j++)
    nums[j] = 0;
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

  moveZeroes(v);

  for (int i = 0; i < n; i++)
  {
    cout << v[i] << " ";
  }

  cout << "\n";

  return 0;
}