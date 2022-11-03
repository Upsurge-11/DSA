#include <bits/stdc++.h>

using namespace std;

int longestPalindrome(vector<string> &words)
{
  int count = 0;
  map<string, int> m;
  for (auto w : words)
  {
    m[w]++;
  }
  bool flag = false;
  for (auto x : words)
  {
    string w = x;
    reverse(w.begin(), w.end());
    if (w != x && m[x] > 0 && m[w] > 0)
    {
      m[x]--;
      m[w]--;
      count += 4;
    }
    else if (w == x && m[x] > 1)
    {
      m[x] -= 2;
      count += 4;
    }
    else if (w == x && !flag && m[x] > 0)
    {
      m[x]--;
      count += 2;
      flag = true;
    }
  }
  return count;
}

int main()
{
  int n;
  cin >> n;
  vector<string> words(n);

  for (int i = 0; i < n; i++)
  {
    cin >> words[i];
  }

  cout << longestPalindrome(words) << "\n";

  return 0;
}