#include <bits/stdc++.h>

using namespace std;

string mergeAlternately(string word1, string word2)
{
  string res = "";
  int i = 0, j = 0, k = 0;
  while (j < word1.length() && k < word2.length())
  {
    if (i % 2 == 0)
      res += word1[j++];
    else
      res += word2[k++];
    i++;
  }
  while (j < word1.length())
    res += word1[j++];
  while (k < word2.length())
    res += word2[k++];

  return res;
}

int main()
{
  string word1, word2;
  cin >> word1 >> word2;

  cout << mergeAlternately(word1, word2) << "\n";

  return 0;
}