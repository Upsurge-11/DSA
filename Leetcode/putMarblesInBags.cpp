#include <bits/stdc++.h>

using namespace std;

long long putMarbles(vector<int> &weights, int k) {
  int n = weights.size();
  vector<int> partitions;
  for (int i = 0; i < n - 1; ++i)
    partitions.push_back(weights[i] + weights[i + 1]);
  sort(partitions.begin(), partitions.end());
  long long minSum = 0, maxSum = 0;
  for (int i = 0; i < k - 1; ++i) {
    minSum += partitions[i];
    maxSum += partitions[n - 2 - i];
  }
  return maxSum - minSum;
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> weights(n);
  for (int i = 0; i < n; ++i)
    cin >> weights[i];
  cout << putMarbles(weights, k) << "\n";
  return 0;
}
