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

  vector<int> v(n - 1);

  for (int i = 0; i < v.size(); i++)
  {
    cin >> v[i];
  }

  sort(v.begin(), v.end());

  for (int i = 0; i < v.size(); i++)
  {
    if (v[i] != i + 1)
    {
      cout << i + 1 << "\n";
      break;
    }
    else if (i == v.size() - 1)
    {
      cout << v.size() + 1 << "\n";
      break;
    }
  }

  return 0;
}