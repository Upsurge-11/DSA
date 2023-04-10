#include <bits/stdc++.h>

using namespace std;

vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k)
{
  priority_queue<pair<double, pair<int, int>>> q;
  for (int i = 0; i < arr.size() - 1; i++)
  {
    for (int j = i + 1; j < arr.size(); j++)
    {
      q.push({double(arr[i]) / arr[j], {arr[i], arr[j]}});
      if (q.size() > k)
        q.pop();
    }
  }
  return {q.top().second.first, q.top().second.second};
}

int main()
{
  int n, k;
  cin >> n >> k;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  vector<int> ans = kthSmallestPrimeFraction(arr, k);
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i] << " ";
  cout << "\n";
  return 0;
}