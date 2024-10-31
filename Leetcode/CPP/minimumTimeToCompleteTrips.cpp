#include <bits/stdc++.h>

using namespace std;

long long minimumTime(vector<int> &time, int totalTrips)
{
  long long low = 0, high = 1e18, mid, ans = 0;
  while (low <= high)
  {
    mid = (low + high) / 2;
    long long trips = 0;
    for (int i = 0; i < time.size(); i++)
    {
      trips += mid / time[i];
      if (trips >= totalTrips)
        break;
    }
    if (trips >= totalTrips)
    {
      ans = mid;
      high = mid - 1;
    }
    else
      low = mid + 1;
  }
  return ans;
}

int main()
{
  int n, totalTrips;
  cin >> n >> totalTrips;
  vector<int> time(n);
  for (int i = 0; i < n; i++)
    cin >> time[i];
  cout << minimumTime(time, totalTrips) << "\n";

  return 0;
}