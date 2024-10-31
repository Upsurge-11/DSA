#include <bits/stdc++.h>

using namespace std;

void sortColors(vector<int> &nums)
{
  sort(nums.begin(), nums.end());
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

  sortColors(v);

  for (int i = 0; i < n; i++)
  {
    cout << v[i] << " ";
  }
  cout << "\n";

  return 0;
}