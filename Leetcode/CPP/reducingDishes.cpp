#include <bits/stdc++.h>

using namespace std;

int maxSatisfaction(vector<int> &satisfaction)
{
  int n = satisfaction.size();
  sort(satisfaction.begin(), satisfaction.end());
  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    int sum = 0;
    for (int j = i; j < n; j++)
      sum += (j - i + 1) * satisfaction[j];
    ans = max(ans, sum);
  }
  return ans;
}

int main()
{
  int n;
  cin >> n;
  vector<int> satisfaction(n);
  for (int i = 0; i < n; i++)
    cin >> satisfaction[i];

  cout << maxSatisfaction(satisfaction) << "\n";

  return 0;
}