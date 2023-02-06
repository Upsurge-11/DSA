#include <bits/stdc++.h>

using namespace std;

vector<int> findAnagrams(string s, string p)
{
  vector<int> res;
  int n = s.size();
  int m = p.size();
  if (n < m)
    return res;
  vector<int> sFreq(26, 0);
  vector<int> pFreq(26, 0);
  for (int i = 0; i < m; i++)
  {
    sFreq[s[i] - 'a']++;
    pFreq[p[i] - 'a']++;
  }
  if (sFreq == pFreq)
    res.push_back(0);
  for (int i = m; i < n; i++)
  {
    sFreq[s[i] - 'a']++;
    sFreq[s[i - m] - 'a']--;
    if (sFreq == pFreq)
      res.push_back(i - m + 1);
  }
  return res;
}

int main()
{
  string s, p;
  cin >> s >> p;
  vector<int> ans = findAnagrams(s, p);
  return 0;
}