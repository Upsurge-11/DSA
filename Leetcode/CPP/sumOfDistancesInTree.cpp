#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>> &graph, vector<int> &res, vector<int> &child, int len, int root, vector<int> &visited)
{
  visited[root] = 1;
  res[0] += len++;
  for (auto &x : graph[root])
  {
    if (visited[x])
      continue;
    dfs(graph, res, child, len, x, visited);
    child[root] += child[x];
  }
  child[root] += 1;
}

void dfs(vector<vector<int>> &graph, vector<int> &res, vector<int> &child, int root, vector<int> &visited, int N)
{
  visited[root] = 1;
  for (auto &x : graph[root])
  {
    if (visited[x])
      continue;
    res[x] = res[root] - child[x] + N - child[x];
    dfs(graph, res, child, x, visited, N);
  }
}

vector<int> sumOfDistancesInTree(int N, vector<vector<int>> &edges)
{
  vector<vector<int>> graph(N, vector<int>());
  for (auto &e : edges)
  {
    graph[e[0]].push_back(e[1]);
    graph[e[1]].push_back(e[0]);
  }
  vector<int> res(N), child(N), visited(N);
  dfs(graph, res, child, 0, 0, visited);
  for (auto &x : visited)
    x = 0;
  dfs(graph, res, child, 0, visited, N);
  return res;
}

int main()
{
  int n, x;
  cin >> n >> x;

  vector<vector<int>> edges(x);

  for (int i = 0; i < x; i++)
  {
    int a, b;
    cin >> a >> b;
    edges[i].push_back(a);
    edges[i].push_back(b);
  }

  vector<int> ans = sumOfDistancesInTree(n, edges);

  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << " ";
  }

  return 0;
}