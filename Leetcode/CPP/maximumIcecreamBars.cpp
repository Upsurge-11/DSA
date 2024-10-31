#include <bits/stdc++.h>

using namespace std;

int maxIceCream(vector<int> &costs, int coins)
{
  sort(costs.begin(), costs.end());
  int ans = 0;
  for (int i = 0; i < costs.size(); i++)
  {
    if (coins - costs[i] >= 0)
    {
      coins -= costs[i];
      ans++;
    }
    else
      break;
    if (coins == 0)
      break;
  }
  return ans;
}

int main()
{
  int n, coins;
  cin >> n >> coins;
  vector<int> costs(n);
  for (int i = 0; i < n; i++)
    cin >> costs[i];

  cout << maxIceCream(costs, coins) << "\n";

  return 0;
}