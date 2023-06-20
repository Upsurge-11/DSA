#include <bits/stdc++.h>

using namespace std;

int mySqrt(int x)
{
  long long low = 1, high = x, ans = -1;
  while (low <= high)
  {
    long long mid = (low + high) / 2;
    if (mid * mid == (long long)x)
      return mid;
    else if (mid * mid < (long long)x)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return high;
}

int main()
{
  int x;
  cin >> x;
  cout << mySqrt(x) << "\n";

  return 0;
}