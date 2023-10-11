#include <bits/stdc++.h>

using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
  sort(strs.begin(), strs.end());
  string ans = "";
  string start = strs[0], end = strs[strs.size() - 1];
  for (int i = 0; i < min(start.size(), end.size()); i++)
  {
    if (start[i] == end[i])
      ans += start[i];
    else
      break;
  }
  return ans;
}

int main()
{
  int n;
  cin >> n;
  vector<string> strs(n);
  for (int i = 0; i < n; i++)
    cin >> strs[i];
  cout << longestCommonPrefix(strs) << "\n";
  return 0;
}