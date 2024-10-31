#include <bits/stdc++.h>

using namespace std;

int lengthOfLongestSubstring(string s) {
  int ans = 0, maxi = 0;
  unordered_map<char, int> mp;
  for (int i = 0; i < s.size(); i++) {
    if (mp.find(s[i]) == mp.end()) {
      maxi++;
      mp[s[i]] = i;
    } else {
      ans = max(ans, maxi);
      maxi = 0;
      i = mp[s[i]];
      mp.clear();
    }
  }
  if (maxi > ans) {
    ans = maxi;
  }
  return ans;
}

int main() {
  string s;
  cin >> s;
  cout << lengthOfLongestSubstring(s) << "\n";
  return 0;
}
