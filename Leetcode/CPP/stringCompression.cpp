#include <bits/stdc++.h>

using namespace std;

int compress(vector<char> &chars)
{
  int n = chars.size();
  int i = 0, j = 0;
  while (i < n)
  {
    int count = 0;
    char c = chars[i];
    while (i < n && chars[i] == c)
    {
      i++;
      count++;
    }
    chars[j++] = c;
    if (count > 1)
    {
      string s = to_string(count);
      for (char c : s)
        chars[j++] = c;
    }
  }
  return j;
}

int main()
{
  int n;
  cin >> n;
  vector<char> chars(n);
  for (int i = 0; i < n; i++)
    cin >> chars[i];
  cout << compress(chars) << "\n";
  return 0;
}