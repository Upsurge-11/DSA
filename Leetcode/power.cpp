#include <bits/stdc++.h>

using namespace std;

double func(double x, int n) {
  if (n == 0) {
    return 1;
  }
  return x * func(x, n - 1);
}

double myPow(double x, int n) {
  if (n == INT_MAX)
    return (x == 1) ? 1 : (x == -1) ? -1 : 0;
  if (n == INT_MIN)
    return (x == 1 || x == -1) ? 1 : 0;
  double num = 1;
  if (n >= 0) {
    num = func(x, n);
  } else {
    n = -n;
    num = func(x, n);
    num = 1.0 / num;
  }
  return num;
}

int main() {
  double x;
  cin >> x;
  int n;
  cin >> n;
  cout << myPow(x, n) << "\n";
  return 0;
}
