#include <bits/stdc++.h>

using namespace std;

int findKthPositive(vector<int> &arr, int k) {
  int n = arr[arr.size() - 1], count = 0;
  vector<int> freq(n + k + 1, 0);
  for (int i = 0; i < arr.size(); i++)
    freq[arr[i]] = 1;
  for (int i = 1; i < freq.size(); i++) {
    if (freq[i] == 0)
      count++;
    if (count == k)
      return i;
  }
  return -1;
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  cout << findKthPositive(arr, k) << "\n";

  return 0;
}
