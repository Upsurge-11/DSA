#include <bits/stdc++.h>

using namespace std;

int fib(vector<int> &dp, int n)
{
  if (n == 0 || n == 1)
  {
    return n;
  }
  if (dp[n] != -1)
  {
    return dp[n];
  }
  dp[n] = fib(dp, n - 1) + fib(dp, n - 2);
  return dp[n];
}

int main()
{
  int n;
  cin >> n;
  vector<int> v(n + 1, -1);
  cout << fib(v, n) << "\n";
  return 0;
}