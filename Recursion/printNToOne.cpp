#include <bits/stdc++.h>

using namespace std;

void printN(int n)
{
  if (n == 0)
    return;
  cout << n << "\n";
  printN(n - 1);
}

int main()
{
  int n;
  cin >> n;
  printN(n);

  return 0;
}