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

  int t;
  cin >> t;

  while (t--)
  {
    int x, y;
    cin >> y >> x;
    int z = max(x, y);
    int z2 = z * z;
    int ans;
    if (z % 2 == 0)
    {
      if (z == y)
        ans = z2 - x + 1;
      else
        ans = z2 - 2 * z + y + 1;
    }
    else
    {
      if (z == x)
        ans = z2 - y + 1;
      else
        ans = z2 - 2 * z + x + 1;
    }
    cout << ans << "\n";
  }

  return 0;
}