#include <bits/stdc++.h>

using namespace std;

bool wordPattern(string pattern, string s)
{
  map<char, string> mp;
  set<char> unique;
  vector<string> store;
  int i = 0, j;
  string temp = "";
  while (i < s.size())
  {
    if (i == s.size() - 1)
    {
      temp += s[i++];
      store.push_back(temp);
      continue;
    }
    if (s[i] != ' ')
    {
      temp += s[i++];
      continue;
    }
    else
    {
      store.push_back(temp);
      temp = "";
      i++;
      continue;
    }
  }
  if (pattern.size() != store.size())
    return false;

  for (i = 0; i < store.size(); i++)
  {
    unique.insert(pattern[i]);
    if (mp.find(pattern[i]) == mp.end())
      mp[pattern[i]] = store[i];
    else
    {
      if (mp[pattern[i]] != store[i])
        return false;
    }
  }

  vector<char> uni(unique.begin(), unique.end());

  for (i = 0; i < uni.size(); i++)
  {
    for (j = i + 1; j < uni.size(); j++)
    {
      if (mp[uni[i]] == mp[uni[j]])
        return false;
    }
  }

  return true;
}

int main()
{
  string pattern, s;
  cin >> pattern;

  if (wordPattern(pattern, s))
    cout
        << "True\n";
  else
    cout << "False\n";

  return 0;
}