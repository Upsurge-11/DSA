#include <bits/stdc++.h>

using namespace std;

vector<vector<string>> partition(string s)
{
}

int main()
{
  string s;
  cin >> s;
  vector<vector<string>> ans = partition(s);
  for (int i = 0; i < ans.size(); i++)
  {
    for (int j = 0; j < ans[i].size(); j++)
      cout << ans[i][j] << " ";
    cout << "\n";
  }

  return 0;
}