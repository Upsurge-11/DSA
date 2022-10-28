#include <bits/stdc++.h>

using namespace std;

// int climbStairs(int n)
// {
//   if (n == 0 || n == 1)
//     return 1;
//   return climbStairs(n - 1) + climbStairs(n - 2);
// }

int climbStairs(int n)
{
  int a = 1;
  int b = 1;
  int c;
  for (int i = 2; i <= n; i++)
  {
    c = a + b;
    a = b;
    b = c;
  }
  return b;
}

int main()
{
  int n;
  cin >> n;
  cout << climbStairs(n) << "\n";

  return 0;
}