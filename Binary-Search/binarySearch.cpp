#include <bits/stdc++.h>

using namespace std;

int binarySearch(int l, int r, vector<int> &v, int x) {
  if (l > r)
    return -1;
  int mid = (l + r) / 2;
  if (v[mid] == x)
    return mid;
  if (v[mid] > x)
    return binarySearch(l, mid - 1, v, x);
  return binarySearch(mid + 1, r, v, x);
}

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  int x;
  cin >> x;
  cout << binarySearch(0, n - 1, v, x) << "\n";
  return 0;
}
