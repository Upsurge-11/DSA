#include <bits/stdc++.h>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
  unordered_map<string, vector<string>> mp;
  for (string s : strs)
  {
    string t = s;
    sort(t.begin(), t.end());
    mp[t].push_back(s);
  }
  vector<vector<string>> anagrams;
  for (auto p : mp)
  {
    anagrams.push_back(p.second);
  }
  return anagrams;
}

int main()
{
  int n;
  cin >> n;
  vector<string> strs(n);

  for (int i = 0; i < n; i++)
  {
    cin >> strs[i];
  }

  vector<vector<string>> ans = groupAnagrams(strs);

  for (int i = 0; i < ans.size(); i++)
  {
    for (int j = 0; j < ans[i].size(); j++)
    {
      cout << ans[i][j] << " ";
    }
    cout << "\n";
  }

  return 0;
}