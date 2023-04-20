#include <bits/stdc++.h>

using namespace std;

vector<int> bellmanFord(int V, vector<vector<int>> &edges, int S)
{
  vector<int> dist(V, INT_MAX);
  dist[S] = 0;
  for (int i = 0; i < V - 1; i++)
  {
    for (auto edge : edges)
    {
      int u = edge[0];
      int v = edge[1];
      int w = edge[2];
      if (dist[u] != INT_MAX && dist[u] + w < dist[v])
        dist[v] = dist[u] + w;
    }
  }
  for (auto edge : edges)
  {
    int u = edge[0];
    int v = edge[1];
    int w = edge[2];
    if (dist[u] != INT_MAX && dist[u] + w < dist[v])
    {
      return {-1};
    }
  }
  return dist;
}

int main()
{
  int V, E;
  cin >> V >> E;
  vector<vector<int>> edges;
  for (int i = 0; i < E; i++)
  {
    int u, v, w;
    cin >> u >> v >> w;
    edges.push_back({u, v, w});
  }
  int S;
  cin >> S;
  vector<int> dist = bellmanFord(V, edges, S);
  for (int i = 0; i < V; i++)
    cout << i << " " << dist[i] << endl;

  return 0;
}