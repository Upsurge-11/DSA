#include <bits/stdc++.h>

using namespace std;

vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src)
{
  vector<int> adj[N];
  for (auto it : edges)
  {
    adj[it[0]].push_back(it[1]);
    adj[it[1]].push_back(it[0]);
  }
  vector<int> dist(N, INT_MAX);
  dist[src] = 0;
  queue<int> q;
  q.push(src);
  while (!q.empty())
  {
    int node = q.front();
    q.pop();
    for (auto it : adj[node])
    {
      if (dist[node] + 1 < dist[it])
      {
        dist[it] = dist[node] + 1;
        q.push(it);
      }
    }
  }
  return dist;
}

int main()
{
  int N, M;
  cin >> N >> M;
  vector<vector<int>> edges(M);
  for (int i = 0; i < M; i++)
  {
    int u, v;
    cin >> u >> v;
    edges[i] = {u, v};
  }
  int src;
  cin >> src;
  vector<int> dist = shortestPath(edges, N, M, src);
  for (int i = 0; i < N; i++)
    cout << dist[i] << " ";
  cout << "\n";

  return 0;
}