#include <bits/stdc++.h>

using namespace std;

int shipWithinDays(vector<int> &weights, int days)
{
  int maxWeight = INT_MIN, totalWeight = 0;
  for (int i = 0; i < weights.size(); i++)
  {
    maxWeight = max(maxWeight, weights[i]);
    totalWeight = totalWeight + weights[i];
  }
  while (maxWeight < totalWeight)
  {
    int midWeight = maxWeight + (totalWeight - maxWeight) / 2;
    int daysNeeded = 1, currWeight = 0;
    for (int i = 0; i < weights.size(); i++)
    {
      if (currWeight + weights[i] > midWeight)
      {
        daysNeeded++;
        currWeight = 0;
      }
      currWeight = currWeight + weights[i];
    }
    if (daysNeeded > days)
      maxWeight = midWeight + 1;
    else
      totalWeight = midWeight;
  }
  return maxWeight;
}

int main()
{
  int n, days;
  cin >> n >> days;
  vector<int> weights(n);
  for (int i = 0; i < n; i++)
    cin >> weights[i];

  cout << shipWithinDays(weights, days) << "\n";

  return 0;
}