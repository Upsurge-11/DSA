#include <bits/stdc++.h>

using namespace std;

int longestCycle(vector<int> &edges)
{
  int ans = -1;
  int currentLength = 1;
  vector<int> len(edges.size(), 0);

  for (int i = 0; i < edges.size(); ++i)
  {
    if (len[i])
      continue;
    int initialLength = currentLength;
    int u = i;
    while (u != -1 && !len[u])
    {
      len[u] = currentLength++;
      u = edges[u];
    }
    if (u != -1 && len[u] >= initialLength)
      ans = max(ans, currentLength - len[u]);
  }
  return ans;
}

int main()
{
  int n;
  cin >> n;
  vector<int> edges(n);
  for (int i = 0; i < n; i++)
    cin >> edges[i];
  cout << longestCycle(edges) << "\n";

  return 0;
}