#include <bits/stdc++.h>

using namespace std;

void cleanString(string &s)
{
  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] >= 'A' && s[i] <= 'Z')
      s[i] += 32;
    if (s[i] >= 'a' && s[i] <= 'z')
      continue;
    if (s[i] >= '0' && s[i] <= '9')
      continue;
    else
      s[i] = '*';
  }
  string str = "";
  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] != '*')
      str += s[i];
  }
  s = str;
}

bool palindromeUtility(string s)
{
  if (s.length() == 0 || s.length() == 1)
    return true;
  if (s[0] == s[s.length() - 1])
    return palindromeUtility(s.substr(1, s.length() - 2));
  return false;
}

bool isPalindrome(string s)
{
  cleanString(s);
  return palindromeUtility(s);
}

int main()
{
  string s;
  cin >> s;
  if (isPalindrome(s))
    cout << "Palindrome" << endl;
  else
    cout << "Not Palindrome" << endl;

  return 0;
}