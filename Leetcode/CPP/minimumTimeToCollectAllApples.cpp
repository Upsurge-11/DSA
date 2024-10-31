#include <bits/stdc++.h>

using namespace std;

int dfs(vector<bool> &hasApple, int node, int d, int prev, vector<vector<int>> &adjList)
{
  int result = 0, temp;
  for (int &i : adjList[node])
    if (i != prev)
    {
      temp = dfs(hasApple, i, d + 1, node, adjList);
      if (temp)
        result += temp - d;
    }
  return result || hasApple[node] ? result + d : 0;
}

int minTime(int n, vector<vector<int>> &edges, vector<bool> &hasApple)
{
  vector<vector<int>> adjList(n);
  for (vector<int> &e : edges)
    adjList[e[0]].push_back(e[1]), adjList[e[1]].push_back(e[0]);
  return dfs(hasApple, 0, 0, -1, adjList) * 2;
}

int main()
{
  int n, x;
  cin >> n >> x;
  vector<vector<int>> edges(x, vector<int>(2));
  vector<bool> hasApple(n);

  for (int i = 0; i < x; i++)
  {
    for (int j = 0; j < 2; j++)
      cin >> edges[i][j];
  }

  for (int i = 0; i < n; i++)
  {
    int z;
    cin >> z;
    hasApple[i] = z;
  }

  cout << minTime(n, edges, hasApple) << "\n";

  return 0;
}