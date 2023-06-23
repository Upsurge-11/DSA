#include <bits/stdc++.h>

using namespace std;

int nthRoot(int n, int m) {
  int low = 1, high = m, mid;
  while (low <= high) {
    mid = (low + high) / 2;
    if (pow(mid, n) == m)
      return mid;
    else if (pow(mid, n) < m)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return -1;
}

int main() {
  int n, m;
  cin >> m >> n;
  cout << nthRoot(n, m) << "\n";

  return 0;
}
