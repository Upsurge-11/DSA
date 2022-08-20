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

  string s;
  cin >> s;

  int ans = 1;
  int count = 1;
  char c = s[0];

  for (int i = 1; i < s.size(); i++)
  {
    if (s[i] == c)
    {
      ans++;
      count = max(ans, count);
    }
    else
    {
      count = max(ans, count);
      c = s[i];
      ans = 1;
    }
  }

  cout << count << "\n";

  return 0;
}