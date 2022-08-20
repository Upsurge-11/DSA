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
  while (n != 1)
  {
    cout << n << " ";
    if (n % 2 == 0)
      n /= 2;
    else
      n = n * 3 + 1;
  }
  cout << n << " ";

  return 0;
}