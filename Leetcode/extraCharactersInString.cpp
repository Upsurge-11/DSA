#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

int func(int ind, string &s, unordered_set<string> &st, vector<int> &dp) {
  if (ind >= s.size())
    return 0;
  if (dp[ind] != -1)
    return dp[ind];
  int res = INT_MAX;
  for (int i = 1; ind + i <= s.size(); i++) {
    string temp = s.substr(ind, i);
    if (st.find(temp) != st.end()) {
      res = min(res, func(ind + i, s, st, dp));
    }
  }
  res = min(res, 1 + func(ind + 1, s, st, dp));
  return dp[ind] = res;
}

int minExtraChar(string s, vector<string> &dictionary) {
  int n = s.size();
  vector<int> dp(n + 1, -1);
  unordered_set<string> st;
  for (int i = 0; i < dictionary.size(); i++)
    st.insert(dictionary[i]);
  return func(0, s, st, dp);
}

int main() {
  string s;
  cin >> s;
  int n;
  cin >> n;
  vector<string> dictionary(n);
  for (int i = 0; i < n; i++)
    cin >> dictionary[i];
  cout << minExtraChar(s, dictionary) << "\n";

  return 0;
}
