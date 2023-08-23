#include <bits/stdc++.h>

using namespace std;

string reorganizeString(string s)
{
  int mostFreq = 0;
  vector<int> freq(26, 0);
  for (char c : s)
  {
    if (++freq[c - 'a'] > freq[mostFreq])
      mostFreq = c - 'a';
  }
  if (2 * freq[mostFreq] - 1 > s.size())
    return "";

  int i = 0;
  while (freq[mostFreq] > 0)
  {
    s[i] = 'a' + mostFreq;
    freq[mostFreq]--;
    i = i + 2;
  }
  for (int j = 0; j < 26; j++)
  {
    while (freq[j])
    {
      if (i >= s.size())
        i = 1;
      s[i] = 'a' + j;
      freq[j]--;
      i = i + 2;
    }
  }
  return s;
}

int main()
{
  string s;
  cin >> s;
  cout << reorganizeString(s) << "\n";
  return 0;
}