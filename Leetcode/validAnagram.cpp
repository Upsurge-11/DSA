#include <bits/stdc++.h>

using namespace std;

bool isAnagram(string s, string t)
{
  bool ans = true;
  vector<int> alphabets1(26, 0);
  vector<int> alphabets2(26, 0);
  if (s.size() != t.size())
    return false;
  for (int i = 0; i < s.size(); i++)
  {
    alphabets1[s[i] - 'a']++;
    alphabets2[t[i] - 'a']++;
  }
  for (int i = 0; i < 26; i++)
  {
    if (alphabets1[i] != alphabets2[i])
      return false;
  }
  return true;
}

int main()
{
  string s, t;
  cin >> s >> t;
  if (isAnagram(s, t))
  {
    cout << "Is Anagram\n";
  }
  else
  {
    cout << "Is Not Anagram\n";
  }
  return 0;
}