#include <bits/stdc++.h>

using namespace std;

// int fib(int n)
// {
//   vector<int> dp(n + 1, 0);
//   dp[1] = 1;
//   for (int i = 2; i <= n; i++)
//   {
//     dp[i] = dp[i - 1] + dp[i - 2];
//   }
//   return dp[n];
// }

int fib(int n)
{
  int a = 0;
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
  cout << fib(n) << "\n";
  return 0;
}