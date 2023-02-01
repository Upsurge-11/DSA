#include <bits/stdc++.h>

using namespace std;

string gcdOfStrings(string str1, string str2)
{
  if (str1 + str2 != str2 + str1)
    return "";
  return str1.substr(0, __gcd(str1.size(), str2.size()));
}

int main()
{
  string s, t;
  cin >> s >> t;
  cout << gcdOfStrings(s, t) << "\n";

  return 0;
}