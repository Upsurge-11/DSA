#include <bits/stdc++.h>

using namespace std;

double maxProbability(int n, vector<vector<int>> &edges,
                      vector<double> &succProb, int start, int end) {
  vector<vector<pair<int, double>>> graph(n);
  for (int i = 0; i < edges.size(); ++i) {
    graph[edges[i][0]].push_back({edges[i][1], succProb[i]});
    graph[edges[i][1]].push_back({edges[i][0], succProb[i]});
  }
  vector<double> prob(n, 0);
  prob[start] = 1;
  priority_queue<pair<double, int>> pq;
  pq.push({1, start});
  while (!pq.empty()) {
    double p = pq.top().first;
    int u = pq.top().second;
    pq.pop();
    if (u == end)
      return p;
    for (auto g : graph[u]) {
      int v = g.first;
      double w = g.second;
      if (prob[v] < p * w) {
        prob[v] = p * w;
        pq.push({prob[v], v});
      }
    }
  }
  return 0;
}

int main() {
  int n, e;
  cin >> n >> e;
  vector<vector<int>> edges(e, vector<int>(2));
  vector<double> succProb(e);
  for (int i = 0; i < e; i++)
    cin >> edges[i][0] >> edges[i][1] >> succProb[i];
  int start, end;
  cin >> start >> end;
  cout << maxProbability(n, edges, succProb, start, end) << "\n";

  return 0;
}
