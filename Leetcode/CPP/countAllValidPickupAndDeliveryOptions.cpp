#include <bits/stdc++.h>

using namespace std;

int countOrders(int n, long res = 1)
{
  return n ? countOrders(n - 1, res * (n * 2 - 1) * n % long(1e9 + 7)) : res;
}

int main()
{
  int n;
  cin >> n;
  cout << countOrders(n) << "\n";
  return 0;
}