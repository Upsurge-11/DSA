#include <bits/stdc++.h>

using namespace std;

string removeStars(string s)
{
  string ans = "";
  stack<int> nonStarInd;
  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] != '*')
      nonStarInd.push(i);
    else
    {
      if (!nonStarInd.empty())
      {
        int ind = nonStarInd.top();
        nonStarInd.pop();
        s[ind] = '?';
        s[i] = '?';
      }
    }
  }
  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] != '?')
      ans += s[i];
  }
  return ans;
}

int main()
{
  string s;
  cin >> s;
  cout << removeStars(s) << "\n";
  return 0;
}