#include <bits/stdc++.h>

using namespace std;

int kthSmallest(vector<vector<int>> &matrix, int k)
{
  priority_queue<int> pq;
  for (int i = 0; i < matrix.size(); i++)
  {
    for (int j = 0; j < matrix.size(); j++)
    {
      pq.push(matrix[i][j]);
      if (pq.size() > k)
        pq.pop();
    }
  }
  return pq.top();
}

int main()
{
  int n;
  cin >> n;
  vector<vector<int>> matrix(n, vector<int>(n));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> matrix[i][j];
    }
  }

  int k;
  cin >> k;
  int ans = kthSmallest(matrix, k);
  cout << ans << "\n";
  return 0;
}