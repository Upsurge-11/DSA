#include <bits/stdc++.h>

using namespace std;

bool check(int mid, int cows, vector<int> &stalls) {
  int count = 1;
  int last = stalls[0];
  for (int i = 1; i < stalls.size(); i++) {
    if (stalls[i] - last >= mid) {
      last = stalls[i];
      count++;
    }
    if (count == cows)
      return true;
  }
  return false;
}

int aggressiveCows(vector<int> &stalls, int cows) {
  sort(stalls.begin(), stalls.end());
  int low = 0;
  int high = stalls[stalls.size() - 1] - stalls[0];
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (check(mid, cows, stalls))
      low = mid + 1;
    else
      high = mid - 1;
  }
  return high;
}

int main() {
  int n, cows;
  cin >> n >> cows;
  vector<int> stalls(n);
  for (int i = 0; i < n; i++)
    cin >> stalls[i];
  cout << aggressiveCows(stalls, cows) << "\n";

  return 0;
}
