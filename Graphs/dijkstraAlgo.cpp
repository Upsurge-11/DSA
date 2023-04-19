#include <bits/stdc++.h>

using namespace std;

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  vector<int> dist(V, INT_MAX);
  dist[S] = 0;
  pq.push({0, S});
  while (!pq.empty())
  {
    int dis = pq.top().first;
    int node = pq.top().second;
    pq.pop();
    for (auto it : adj[node])
    {
      int adjNode = it[0];
      int edgeWeight = it[1];
      if (dis + edgeWeight < dist[adjNode])
      {
        dist[adjNode] = dis + edgeWeight;
        pq.push({dist[adjNode], adjNode});
      }
    }
  }
  return dist;
}

int main()
{
  int V, E;
  cin >> V >> E;
  vector<vector<int>> adj[V];
  for (int i = 0; i < E; i++)
  {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }
  int S;
  cin >> S;
  vector<int> dist = dijkstra(V, adj, S);
  for (int i = 0; i < V; i++)
    cout << dist[i] << " ";
  cout << "\n";
  return 0;
}