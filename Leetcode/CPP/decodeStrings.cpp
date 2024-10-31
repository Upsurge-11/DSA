#include <bits/stdc++.h>

using namespace std;

string solve(string &s, int l, int r, unordered_map<int, int> &closePos)
{
  string ans = "";
  int num = 0;
  while (l <= r)
  {
    char c = s[l];
    if (isdigit(c))
      num = num * 10 + c - '0';
    else if (c == '[')
    {
      string sub = solve(s, l + 1, closePos[l] - 1, closePos);
      for (int i = 0; i < num; ++i)
        ans += sub;
      num = 0;
      l = closePos[l];
    }
    else
      ans += c;
    l += 1;
  }
  return ans;
}

string decodeString(string s)
{
  stack<int> st;
  unordered_map<int, int> closePos;
  for (int i = 0; i < s.size(); ++i)
  {
    if (s[i] == '[')
      st.push(i);
    else if (s[i] == ']')
    {
      closePos[st.top()] = i;
      st.pop();
    }
  }
  return solve(s, 0, s.size() - 1, closePos);
}

int main()
{
  string s;
  cin >> s;
  cout << decodeString(s) << "\n";

  return 0;
}