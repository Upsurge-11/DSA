#include <bits/stdc++.h>

using namespace std;

bool detectCapitalUse(string word)
{
  bool ans;
  int n = word.size();
  if (n == 1)
    return true;
  if (n == 2)
  {
    if ((word[1] >= 'A' && word[1] <= 'Z') && (word[0] >= 'a' && word[0] <= 'z'))
      return false;
    return true;
  }
  if (word[0] >= 'a' && word[0] <= 'z')
  {
    for (int i = 1; i < n; i++)
    {
      if (word[i] >= 'A' && word[i] <= 'Z')
        return false;
    }
    return true;
  }
  if ((word[0] >= 'A' && word[0] <= 'Z') && (word[1] >= 'A' && word[1] <= 'Z'))
  {
    for (int i = 2; i < n; i++)
    {
      if (word[i] >= 'a' && word[i] <= 'z')
        return false;
    }
    return true;
  }
  if ((word[0] >= 'A' && word[0] <= 'Z') && (word[1] >= 'a' && word[1] <= 'z'))
  {
    for (int i = 2; i < n; i++)
    {
      if (word[i] >= 'A' && word[i] <= 'Z')
        return false;
    }
    return true;
  }
  return true;
}

int main()
{
  string word;
  cin >> word;

  if (detectCapitalUse(word))
    cout << "True\n";
  else
    cout << "False\n";
  return 0;
}