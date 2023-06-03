#include <bits/stdc++.h>

using namespace std;

int lowerBound(int n, vector<int> &v, int x) {
  int l = 0, r = n - 1, ans = n;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (v[mid] >= x) {
      ans = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  return ans;
}

int upperBound(int n, vector<int> &v, int x) {
  int l = 0, r = n - 1, ans = n;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (v[mid] > x) {
      ans = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  return ans;
}

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  int x;
  cin >> x;
  cout << lowerBound(n, v, x) << "\n";

  return 0;
}
