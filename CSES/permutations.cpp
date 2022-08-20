#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  if (n == 1)
  {
    cout << "1\n";
  }
  else if (n < 4)
  {
    cout << "NO SOLUTION\n";
  }
  else
  {
    for (int i = 1; i <= n; i++)
    {
      if (i % 2 == 0)
      {
        cout << i << " ";
      }
    }
    for (int i = 1; i <= n; i++)
    {
      if (i % 2 != 0)
      {
        cout << i << " ";
      }
    }
    cout << "\n";
  }

  return 0;
}