#include <bits/stdc++.h>

using namespace std;

void func(int start, const vector<int> &cookies, vector<int> &children, int k,
          int &ans) {
  int n = cookies.size();
  if (start == n) {
    int maxi = INT_MIN;
    for (int i = 0; i < k; i++) {
      maxi = max(maxi, children[i]);
    }
    ans = min(ans, maxi);
    return;
  }
  for (int i = 0; i < k; i++) {
    children[i] += cookies[start];
    func(start + 1, cookies, children, k, ans);
    children[i] -= cookies[start];
  }
}

int distributeCookies(vector<int> &cookies, int k) {
  int ans = INT_MAX;
  vector<int> children(k, 0);
  func(0, cookies, children, k, ans);
  return ans;
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> cookies(n);
  for (int i = 0; i < n; i++)
    cin >> cookies[i];
  cout << distributeCookies(cookies, k) << "\n";

  return 0;
}
