#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> adj[n + 1];
  for (int i = 0; i < n; i++)
  {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < adj[i].size(); j++)
      cout << adj[i][j] << " ";
    cout << "\n";
  }

  return 0;
}