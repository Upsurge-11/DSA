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

  vector<int> v(n);

  for (int i = 0; i < n; i++)
  {
    cin >> v[i];
  }

  int ans = 0;

  for (int i = 1; i < n; i++)
  {
    if (v[i] < v[i - 1])
    {
      ans += abs(v[i - 1] - v[i]);
      v[i] = v[i - 1];
    }
  }

  cout << ans << "\n";

  return 0;
}