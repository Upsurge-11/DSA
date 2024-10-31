#include <bits/stdc++.h>

using namespace std;

int minDeletions(string s)
{
  vector<int> freq(26, 0);
  for (char c : s)
    freq[c - 'a']++;
  sort(freq.begin(), freq.end());
  int ans = 0;
  for (int i = 24; i >= 0; i--)
  {
    if (freq[i] == 0)
      break;
    if (freq[i] >= freq[i + 1])
    {
      int prev = freq[i];
      freq[i] = max(0, freq[i + 1] - 1);
      ans += prev - freq[i];
    }
  }
  return ans;
}

int main()
{
  string s;
  cin >> s;
  cout << minDeletions(s) << "\n";
  return 0;
}