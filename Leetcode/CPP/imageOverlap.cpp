#include <bits/stdc++.h>

using namespace std;

int largestOverlap(vector<vector<int>> &img1, vector<vector<int>> &img2)
{
  int n = img1.size();
  int ans = 0;
  for (int i = -n + 1; i < n; i++)
  {
    for (int j = -n + 1; j < n; j++)
    {
      int count = 0;
      for (int k = 0; k < n; k++)
      {
        for (int l = 0; l < n; l++)
        {
          if (k + i >= 0 && k + i < n && l + j >= 0 && l + j < n && img1[k][l] == 1 && img2[k + i][l + j] == 1)
          {
            count++;
          }
        }
      }
      ans = max(ans, count);
    }
  }
  return ans;
}

int main()
{
  int n;
  cin >> n;
  vector<vector<int>> img1(n, vector<int>(n));
  vector<vector<int>> img2(n, vector<int>(n));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> img1[i][j];
    }
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> img2[i][j];
    }
  }

  cout << largestOverlap(img1, img2) << "\n";

  return 0;
}