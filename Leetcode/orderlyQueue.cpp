#include <bits/stdc++.h>

using namespace std;

string orderlyQueue(string s, int k)
{
  if (k > 1)
  {
    sort(s.begin(), s.end());
    return s;
  }
  string ans = s;
  for (int i = 0; i < s.size(); i++)
  {
    string t = s.substr(i) + s.substr(0, i);
    if (t < ans)
      ans = t;
  }
  return ans;
}

int main()
{
  string s;
  cin >> s;
  int k;
  cin >> k;

  cout << orderlyQueue(s, k) << "\n";

  return 0;
}