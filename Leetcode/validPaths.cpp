#include <bits/stdc++.h>

using namespace std;

bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
{
  vector<vector<int>> graph(n);
  for (auto edge : edges)
  {
    graph[edge[0]].push_back(edge[1]);
    graph[edge[1]].push_back(edge[0]);
  }

  vector<bool> visited(n, false);
  queue<int> q;
  q.push(source);
  visited[source] = true;

  while (!q.empty())
  {
    int node = q.front();
    q.pop();

    if (node == destination)
      return true;

    for (auto neighbour : graph[node])
    {
      if (!visited[neighbour])
      {
        q.push(neighbour);
        visited[neighbour] = true;
      }
    }
  }

  return false;
}

int main()
{
  int n, edge;
  cin >> n >> edge;
  vector<vector<int>> edges;
  for (int i = 0; i < edge; i++)
  {
    int u, v;
    cin >> u >> v;
    edges.push_back({u, v});
  }

  int source, destination;
  cin >> source >> destination;

  if (validPath(n, edges, source, destination))
    cout << "Path is present\n";
  else
    cout << "Path is not present\n";

  return 0;
}