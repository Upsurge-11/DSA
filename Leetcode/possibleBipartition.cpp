#include <bits/stdc++.h>

using namespace std;

bool possibleBipartition(int n, vector<vector<int>> &dislikes)
{
  vector<vector<int>> graph(n + 1);
  vector<int> temp(n + 1, 0);

  for (int i = 0; i < dislikes.size(); i++)
  {
    graph[dislikes[i][0]].push_back(dislikes[i][1]);
    graph[dislikes[i][1]].push_back(dislikes[i][0]);
  }

  for (int i = 1; i <= n; i++)
  {
    if (temp[i] == 0)
    {
      queue<int> q;
      q.push(i);
      temp[i] = 1;

      while (!q.empty())
      {
        int node = q.front();
        q.pop();

        for (int j = 0; j < graph[node].size(); j++)
        {
          if (temp[graph[node][j]] == 0)
          {
            temp[graph[node][j]] = -temp[node];
            q.push(graph[node][j]);
          }
          else if (temp[graph[node][j]] == temp[node])
          {
            return false;
          }
        }
      }
    }
  }

  return true;
}

int main()
{
  int n, x;
  cin >> n >> x;
  vector<vector<int>> dislikes(x);

  for (int i = 0; i < x; i++)
  {
    int a, b;
    cin >> a >> b;
    dislikes.push_back({a, b});
  }

  if (possibleBipartition(n, dislikes))
  {
    cout << "Partition is Possible.\n";
  }
  else
  {
    cout << "Partition is not Possible.\n";
  }

  return 0;
}