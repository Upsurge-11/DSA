// A pangram is a sentence where every letter of the English alphabet appears at least once.
// Given a string sentence containing only lowercase English letters, return true if sentence is a pangram, or false otherwise.

#include <bits/stdc++.h>

using namespace std;

bool checkIfPangram(string sentence)
{
  vector<int> freqAlpha(26, 0);
  for (int i = 0; i < sentence.size(); i++)
  {
    freqAlpha[sentence[i] - 'a']++;
  }
  for (int i = 0; i < 26; i++)
  {
    if (freqAlpha[i] == 0)
      return false;
  }
  return true;
}

int main()
{
  string s;
  cin >> s;
  if (checkIfPangram(s))
  {
    cout << "Is Panagram.\n";
  }
  else
    cout << "Not a Pangram.\n";

  return 0;
}