#include <bits/stdc++.h>

using namespace std;

bool isPossible(vector<int> &bloomDay, int m, int k, int day)
{
  int count = 0;
  int ans = 0;
  for (int i = 0; i < bloomDay.size(); i++)
  {
    if (bloomDay[i] <= day)
      count++;
    else
    {
      ans += count / k;
      count = 0;
    }
  }
  ans += count / k;
  return ans >= m;
}

int minDays(vector<int> &bloomDay, int m, int k)
{
  if ((long long)m * k > (long long)bloomDay.size())
    return -1;
  int low = *min_element(bloomDay.begin(), bloomDay.end());
  int high = *max_element(bloomDay.begin(), bloomDay.end());
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    if (isPossible(bloomDay, m, k, mid))
      high = mid - 1;
    else
      low = mid + 1;
  }
  return low;
}

int main()
{
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> bloomDay(n);
  for (int i = 0; i < n; i++)
    cin >> bloomDay[i];
  cout << minDays(bloomDay, m, k) << "\n";
  return 0;
}