#include <bits/stdc++.h>

using namespace std;

int reverse(int x)
{
  bool negative = false;
  if (x < 0)
    negative = true;
  x = abs(x);
  long long ans = 0, z = 1, temp = x;
  while (temp > 0)
  {
    z *= 10;
    temp /= 10;
  }
  z /= 10;
  while (x > 0)
  {
    ans += (x % 10) * z;
    z /= 10;
    x /= 10;
  }
  if (negative)
    ans *= -1;
  if (ans > 2147483647 || ans < -2147483648)
    return 0;
  return ans;
}

int main()
{
  int n;
  cin >> n;
  cout << reverse(n) << "\n";
  return 0;
}