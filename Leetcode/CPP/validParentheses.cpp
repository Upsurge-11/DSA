#include <bits/stdc++.h>

using namespace std;

bool isValid(string s)
{
  stack<char> st;
  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] == '(' || s[i] == '{' || s[i] == '[')
      st.push(s[i]);
    else if (s[i] == ')' || s[i] == '}' || s[i] == ']')
    {
      if (st.empty())
        return false;
      else
      {
        char c = st.top();
        if ((s[i] == ')' && c == '(') || (s[i] == '}' && c == '{') || (s[i] == ']' && c == '['))
          st.pop();
        else
          return false;
      }
    }
  }
  if (!st.empty())
    return false;
  return true;
}

int main()
{
  string s;
  cin >> s;
  cout << isValid(s) << "\n";

  return 0;
}