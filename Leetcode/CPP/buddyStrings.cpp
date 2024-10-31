#include <bits/stdc++.h>

using namespace std;

bool buddyStrings(string s, string goal) {
  if (s.size() != goal.size())
    return false;
  if (s == goal) {
    vector<int> freq(26, 0);
    for (int i = 0; i < s.size(); i++) {
      freq[s[i] - 'a']++;
      if (freq[s[i] - 'a'] > 1)
        return true;
    }
    return false;
  }
  int firstIndex = -1, secondIndex = -1;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] != goal[i]) {
      if (firstIndex == -1)
        firstIndex = i;
      else if (secondIndex == -1)
        secondIndex = i;
      else
        return false;
    }
  }
  return (secondIndex != -1 && s[firstIndex] == goal[secondIndex] &&
          s[secondIndex] == goal[firstIndex]);
}

int main() {
  string s, goal;
  cin >> s >> goal;
  cout << buddyStrings(s, goal) << "\n";

  return 0;
}
