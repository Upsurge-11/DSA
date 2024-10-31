#include <bits/stdc++.h>

using namespace std;

int removeStones(vector<vector<int>> &stones)
{
  int n = stones.size();
  vector<int> parent(n);
  for (int i = 0; i < n; i++)
  {
    parent[i] = i;
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
      {
        int p1 = i, p2 = j;
        while (parent[p1] != p1)
        {
          p1 = parent[p1];
        }
        while (parent[p2] != p2)
        {
          p2 = parent[p2];
        }
        parent[p2] = p1;
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    if (parent[i] == i)
    {
      ans++;
    }
  }

  return n - ans;
}

int main()
{
  int n;
  cin >> n;
  vector<vector<int>> stones(n, vector<int>(2));

  for (int i = 0; i < n; i++)
  {
    cin >> stones[i][0] >> stones[i][1];
  }

  cout << removeStones(stones) << "\n";

  return 0;
}