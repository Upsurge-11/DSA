#include <bits/stdc++.h>

using namespace std;

int minDeletionSize(vector<string> &strs)
{
  int n = strs.size();
  int m = strs[0].size();
  int count = 0;
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n - 1; j++)
    {
      if (strs[j + 1][i] < strs[j][i])
      {
        count++;
        break;
      }
    }
  }
  return count;
}

int main()
{
  int n;
  cin >> n;
  vector<string> strs(n);
  for (int i = 0; i < n; i++)
    cin >> strs[i];

  cout << minDeletionSize(strs) << "\n";

  return 0;
}