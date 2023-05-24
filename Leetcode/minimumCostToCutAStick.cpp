#include <bits/stdc++.h>

using namespace std;

int minCost(int n, vector<int> &cuts)
{
}

int main()
{
  int n, k;
  cin >> n >> k;
  vector<int> cuts(n);
  for (int i = 0; i < n; i++)
    cin >> cuts[i];
  cout << minCost(n, cuts) << "\n";

  return 0;
}