#include <bits/stdc++.h>

using namespace std;

int canShipTravel(vector<int> &weights, int capacity)
{
  int days = 1, load = 0;
  for (int i = 0; i < weights.size(); i++)
  {
    if (load + weights[i] > capacity)
    {
      days++;
      load = weights[i];
    }
    else
      load += weights[i];
  }
  return days;
}

int shipWithinDays(vector<int> &weights, int days)
{
  int low = *max_element(weights.begin(), weights.end());
  int high = 0;
  for (int i = 0; i < weights.size(); i++)
    high += weights[i];
  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (canShipTravel(weights, mid) <= days)
      high = mid - 1;
    else
      low = mid + 1;
  }
  return low;
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