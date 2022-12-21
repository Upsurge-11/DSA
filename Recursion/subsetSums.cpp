#include <bits/stdc++.h>

using namespace std;

void subsetSums(vector<int> &arr, vector<int> &ans, int idx, int sum)
{
  if (idx == arr.size())
  {
    ans.push_back(sum);
    return;
  }

  subsetSums(arr, ans, idx + 1, sum + arr[idx]);
  subsetSums(arr, ans, idx + 1, sum);
}

int main()
{
  int n;
  cin >> n;
  vector<int> arr(n);

  for (int i = 0; i < n; i++)
    cin >> arr[i];

  vector<int> ans;

  subsetSums(arr, ans, 0, 0);

  sort(ans.begin(), ans.end());

  for (int i = 0; i < ans.size(); i++)
    cout << ans[i] << " ";

  cout << "\n";

  return 0;
}