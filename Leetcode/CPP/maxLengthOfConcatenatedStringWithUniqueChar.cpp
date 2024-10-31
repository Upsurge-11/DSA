#include <bits/stdc++.h>

using namespace std;

int maxLength(vector<string> &arr)
{
  int n = arr.size();
  vector<int> mask(n);
  for (int i = 0; i < n; i++)
  {
    for (char c : arr[i])
    {
      int bit = 1 << (c - 'a');
      if (mask[i] & bit)
      {
        mask[i] = 0;
        break;
      }
      mask[i] |= bit;
    }
  }
  int ans = 0;
  function<void(int, int)> dfs = [&](int pos, int currMask)
  {
    if (pos == n)
    {
      ans = max(ans, __builtin_popcount(currMask));
      return;
    }
    if ((currMask & mask[pos]) == 0)
    {
      dfs(pos + 1, currMask | mask[pos]);
    }
    dfs(pos + 1, currMask);
  };
  dfs(0, 0);
  return ans;
}

int main()
{
  int n;
  cin >> n;
  vector<string> arr(n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  cout << maxLength(arr) << "\n";

  return 0;
}