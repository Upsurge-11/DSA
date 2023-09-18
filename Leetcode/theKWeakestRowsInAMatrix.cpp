#include <bits/stdc++.h>

using namespace std;

vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
{
  vector<pair<int, int>> strength(mat.size());
  for (int i = 0; i < mat.size(); i++)
    strength[i] = {accumulate(mat[i].begin(), mat[i].end(), 0), i};
  sort(strength.begin(), strength.end());
  vector<int> ans;
  for (int i = 0; i < k; i++)
    ans.push_back(strength[i].second);
  return ans;
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> mat(n, vector<int>(m));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> mat[i][j];
  int k;
  cin >> k;
  vector<int> ans = kWeakestRows(mat, k);
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i] << " ";

  return 0;
}