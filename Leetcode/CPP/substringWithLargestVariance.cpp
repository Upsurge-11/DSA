#include <bits/stdc++.h>

using namespace std;

int largestVariance(string s) {
  vector<int> freq(26);
  for (auto x : s) {
    freq[x - 'a']++;
  }
  int ans = 0;
  for (char i = 'a'; i <= 'z'; i++) {
    for (char j = 'a'; j <= 'z'; j++) {
      if (j == i || freq[i - 'a'] == 0 || freq[j - 'a'] == 0)
        continue;
      for (int k = 1; k <= 2; k++) {
        int A1 = 0;
        int A2 = 0;
        for (auto x : s) {
          if (x == i)
            A1++;
          if (x == j)
            A2++;
          if (A2 > A1) {
            A1 = 0;
            A2 = 0;
          }
          if (A1 > 0 && A2 > 0)
            ans = max(ans, A1 - A2);
        }
        reverse(s.begin(), s.end());
      }
    }
  }
  return ans;
}

int main() {
  string s;
  cin >> s;
  cout << largestVariance(s) << "\n";
  return 0;
}
