#include <bits/stdc++.h>

using namespace std;

string minWindow(string s, string t)
{
  int n = s.size();
  int m = t.size();
  if (n < m)
    return "";
  int cnt[256] = {0};
  for (int i = 0; i < m; i++)
    cnt[t[i]]++;
  int left = 0, right = 0;
  int minLen = INT_MAX;
  int minLeft = 0;
  int minRight = 0;
  int curCnt = 0;
  while (right < n)
  {
    if (cnt[s[right]] > 0)
      curCnt++;
    cnt[s[right]]--;
    right++;
    while (curCnt == m)
    {
      if (right - left < minLen)
      {
        minLen = right - left;
        minLeft = left;
        minRight = right;
      }
      cnt[s[left]]++;
      if (cnt[s[left]] > 0)
        curCnt--;
      left++;
    }
  }
  if (minLen == INT_MAX)
    return "";
  return s.substr(minLeft, minLen);
}

int main()
{
  string s, t;
  cin >> s >> t;

  string ans = minWindow(s, t);

  cout << ans << "\n";

  return 0;
}