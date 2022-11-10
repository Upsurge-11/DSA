#include <bits/stdc++.h>

using namespace std;

string removeDuplicates(string s)
{
  string ans;

  for (int i = 0; i < s.size(); i++)
  {
    if (!ans.empty() && ans.back() == s[i])
      ans.pop_back();
    else
      ans.push_back(s[i]);
  }

  return ans;
}

int main()
{
  string s;
  cin >> s;
  cout << removeDuplicates(s) << "\n";

  return 0;
}