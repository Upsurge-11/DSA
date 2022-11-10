#include <bits/stdc++.h>

using namespace std;

string makeGood(string s)
{
  for (int i = 1; i < s.size(); i++)
  {
    if (abs(s[i] - s[i - 1]) == 32)
    {
      s.erase(s.begin() + i);
      s.erase(s.begin() + i - 1);
      i = 0;
    }
  }
  return s;
}

int main()
{
  string s;
  cin >> s;

  string ans = makeGood(s);

  cout << ans << "\n";

  return 0;
}