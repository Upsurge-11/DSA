#include <bits/stdc++.h>

using namespace std;

int strStr(string haystack, string needle)
{
  int n = haystack.size();
  int m = needle.size();
  if (m == 0)
    return 0;
  if (n == 0)
    return -1;
  int i = 0, j = 0;
  while (i < n)
  {
    if (haystack[i] == needle[j])
    {
      i++;
      j++;
    }
    else
    {
      i = i - j + 1;
      j = 0;
    }
    if (j == m)
      return i - j;
  }
  return -1;
}

int main()
{
  string haystack, needle;
  cin >> haystack >> needle;
  cout << strStr(haystack, needle) << "\n";

  return 0;
}