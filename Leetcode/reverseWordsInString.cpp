#include <bits/stdc++.h>

using namespace std;

string reverseWords(string s)
{
  string ans = "";
  int n = s.length();
  int i = 0;
  while (i < n)
  {
    while (i < n && s[i] == ' ')
    {
      i++;
    }
    if (i >= n)
    {
      break;
    }
    int j = i + 1;
    while (j < n && s[j] != ' ')
    {
      j++;
    }
    string temp = s.substr(i, j - i);
    if (ans.length() == 0)
    {
      ans = temp;
    }
    else
    {
      ans = temp + " " + ans;
    }
    i = j + 1;
  }
  return ans;
}

int main()
{
  string s;
  getline(cin, s);

  string ans = reverseWords(s);
  cout << ans << "\n";

  return 0;
}