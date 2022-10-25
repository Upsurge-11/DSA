#include <bits/stdc++.h>

using namespace std;

bool arrayStringsAreEqual(vector<string> &word1, vector<string> word2)
{
  string str1 = "", str2 = "";
  for (int i = 0; i < word1.size(); i++)
  {
    str1 += word1[i];
  }

  for (int i = 0; i < word2.size(); i++)
  {
    str2 += word2[i];
  }

  return str1 == str2;
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<string> word1(n);
  vector<string> word2(m);

  for (int i = 0; i < n; i++)
  {
    cin >> word1[i];
  }

  for (int i = 0; i < m; i++)
  {
    cin >> word2[i];
  }

  if (arrayStringsAreEqual(word1, word2))
  {
    cout << "Words are Equivalent.\n";
  }
  else
  {
    cout << "Words are not Equivalent.\n";
  }

  return 0;
}