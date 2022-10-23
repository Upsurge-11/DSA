#include <bits/stdc++.h>

using namespace std;

int maxProfit(vector<int> &prices)
{
  int ans = 0, minPrice = prices[0];
  for (int i = 0; i < prices.size(); i++)
  {
    if (prices[i] < minPrice)
      minPrice = prices[i];
    ans = max(ans, prices[i] - minPrice);
  }
  return ans;
}

int main()
{
  int n;
  cin >> n;
  vector<int> prices(n);
  for (int i = 0; i < n; i++)
  {
    cin >> prices[i];
  }

  cout << maxProfit(prices) << "\n";

  return 0;
}