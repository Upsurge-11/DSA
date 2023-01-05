#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string s, int start, int end)
{
  while (start <= end)
  {
    if (s[start++] != s[end--])
      return false;
  }
  return true;
}

void util(int ind, string s, vector<string> &temp, vector<vector<string>> &ans)
{
  if (ind == s.size())
  {
    ans.push_back(temp);
    return;
  }
  for (int i = ind; i < s.size(); i++)
  {
    if (isPalindrome(s, ind, i))
    {
      temp.push_back(s.substr(ind, i - ind + 1));
      util(i + 1, s, temp, ans);
      temp.pop_back();
    }
  }
}

vector<vector<string>> partition(string s)
{
  vector<vector<string>> ans;
  vector<string> temp;
  util(0, s, temp, ans);
  return ans;
}

int main()
{
  string s;
  cin >> s;
  vector<vector<string>> ans = partition(s);
  for (int i = 0; i < ans.size(); i++)
  {
    for (int j = 0; j < ans[i].size(); j++)
      cout << ans[i][j] << " ";
    cout << "\n";
  }

  return 0;
}