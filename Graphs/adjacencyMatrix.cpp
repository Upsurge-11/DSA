#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> v(n + 1, vector<int>(n + 1, 0));
  for (int i = 0; i < m; i++)
  {
    int a, b;
    cin >> a >> b;
    v[a][b] = 1;
    v[b][a] = 1;
  }

  for (int i = 0; i <= n; i++)
  {
    for (int j = 0; j <= n; j++)
      cout << v[i][j] << " ";
    cout << "\n";
  }

  return 0;
}