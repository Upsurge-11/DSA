#include <bits/stdc++.h>

using namespace std;

string reverseVowels(string s)
{
  int l = 0, r = s.size() - 1;
  while (l < r)
  {
    if (s[l] == 'a' || s[l] == 'e' || s[l] == 'i' || s[l] == 'o' || s[l] == 'u' || s[l] == 'A' || s[l] == 'E' || s[l] == 'I' || s[l] == 'O' || s[l] == 'U')
    {
      if (s[r] == 'a' || s[r] == 'e' || s[r] == 'i' || s[r] == 'o' || s[r] == 'u' || s[r] == 'A' || s[r] == 'E' || s[r] == 'I' || s[r] == 'O' || s[r] == 'U')
      {
        swap(s[l], s[r]);
        l++;
        r--;
      }
      else
      {
        r--;
      }
    }
    else
    {
      l++;
    }
  }
  return s;
}

int main()
{
  string s;
  cin >> s;

  cout << reverseVowels(s) << "\n";

  return 0;
}