#include <bits/stdc++.h>

using namespace std;

int rabinKarp(string source, string target)
{
  int BASE = 1000000;
  if (source == "" or target == "")
    return -1;
  int m = target.size();
  int power = 1;
  for (int i = 0; i < m; i++)
    power = (power * 31) % BASE;
  int targetCode = 0;
  for (int i = 0; i < m; i++)
    targetCode = (targetCode * 31 + target[i]) % BASE;
  int hashCode = 0;
  for (int i = 0; i < source.size(); i++)
  {
    hashCode = (hashCode * 31 + source[i]) % BASE;
    if (i < m - 1)
      continue;
    if (i >= m)
      hashCode = (hashCode - source[i - m] * power) % BASE;
    if (hashCode < 0)
      hashCode += BASE;
    if (hashCode == targetCode)
    {
      if (source.substr(i - m + 1, m) == target)
        return i - m + 1;
    }
  }
  return -1;
}

int repeatedStringMatch(string a, string b)
{
  if (a == b)
    return 1;
  int count = 1;
  string source = a;
  while (source.size() < b.size())
  {
    count++;
    source += a;
  }
  if (source == b)
    return count;
  if (rabinKarp(source, b) != -1)
    return count;
  if (rabinKarp(source + a, b) != -1)
    return count + 1;
  return -1;
}

int main()
{
  string a, b;
  cin >> a >> b;
  cout << repeatedStringMatch(a, b) << "\n";
  return 0;
}