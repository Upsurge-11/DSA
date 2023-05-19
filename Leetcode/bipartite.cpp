#include <bits/stdc++.h>

using namespace std;

bool dfs(int node, int col, vector<int> &color, vector<vector<int>> &graph)
{
  color[node] = col;
  for (auto it : graph[node])
  {
    if (color[it] == -1)
    {
      if (!dfs(it, 1 - col, color, graph))
        return false;
    }
    else if (color[it] == color[node])
      return false;
  }
  return true;
}

bool isBipartite(vector<vector<int>> &graph)
{
  int V = graph.size();
  vector<int> color(V, -1);
  for (int i = 0; i < V; i++)
  {
    if (color[i] == -1)
    {
      if (!dfs(i, 0, color, graph))
        return false;
    }
  }
  return true;
}

int main()
{
  int V, E;
  cin >> V >> E;
  vector<vector<int>> graph(V);
  for (int i = 0; i < E; i++)
  {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
  }
  if (isBipartite(graph))
    cout << "Yes\n";
  else
    cout << "No\n";

  return 0;
}