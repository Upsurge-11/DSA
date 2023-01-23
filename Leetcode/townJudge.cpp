#include <bits/stdc++.h>

using namespace std;

int findJudge(int n, vector<vector<int>> &trust)
{
  vector<int> in(n + 1, 0);
  vector<int> out(n + 1, 0);

  for (int i = 0; i < trust.size(); i++)
  {
    out[trust[i][0]]++;
    in[trust[i][1]]++;
  }

  for (int i = 1; i <= n; i++)
  {
    if (in[i] == n - 1 && out[i] == 0)
      return i;
  }

  return -1;
}

int main()
{
  int n, x;
  cin >> n >> x;
  vector<vector<int>> trust(x, vector<int>(2));
  for (int i = 0; i < x; i++)
    cin >> trust[i][0] >> trust[i][1];

  cout << findJudge(n, trust) << "\n";

  return 0;
}