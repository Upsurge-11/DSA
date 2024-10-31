#include <bits/stdc++.h>

using namespace std;

bool isPossible(vector<int> &batteries, long long time, int computers)
{
  long long totTime = 0;
  for (long long bTime : batteries)
    totTime += min(bTime, time);
  return (totTime >= time * computers);
}

long long maxRunTime(int n, vector<int> &batteries)
{
  long long low = 1, high = 1e14;
  while (low <= high)
  {
    long long mid = low + (high - low) / 2;
    if (isPossible(batteries, mid, n))
      low = mid + 1;
    else
      high = mid - 1;
  }
  return high;
}

int main()
{
  int n, battery;
  cin >> n >> battery;
  vector<int> batteries(battery);
  for (int i = 0; i < battery; i++)
    cin >> batteries[i];

  cout << maxRunTime(n, batteries) << "\n";

  return 0;
}