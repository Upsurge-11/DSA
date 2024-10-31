#include <bits/stdc++.h>

using namespace std;

int maxVowels(string s, int k)
{
  int n = s.size();
  int maxVowels = 0;
  int currVowels = 0;
  int i = 0;
  int j = 0;
  while (j < n)
  {
    if (j - i + 1 < k)
    {
      if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u')
        currVowels++;
      j++;
    }
    else
    {
      if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u')
        currVowels++;
      maxVowels = max(maxVowels, currVowels);
      if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
        currVowels--;
      i++;
      j++;
    }
  }
  return maxVowels;
}

int main()
{
  string s;
  cin >> s;
  int k;
  cin >> k;

  cout << maxVowels(s, k) << "\n";

  return 0;
}