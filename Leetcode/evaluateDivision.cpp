#include <bits/stdc++.h>

using namespace std;

double dfs(unordered_map<string, unordered_map<string, double>> graph, string a, string b, unordered_set<string> visited)
{
  if (a == b)
    return 1.0;
  visited.insert(a);
  for (auto it : graph[a])
  {
    if (visited.find(it.first) == visited.end())
    {
      double res = dfs(graph, it.first, b, visited);
      if (res != -1.0)
        return res * it.second;
    }
  }
  return -1.0;
}

vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
{
  unordered_map<string, unordered_map<string, double>> graph;
  for (int i = 0; i < equations.size(); i++)
  {
    string a = equations[i][0];
    string b = equations[i][1];
    double val = values[i];
    graph[a][b] = val;
    graph[b][a] = 1 / val;
  }
  vector<double> ans;
  for (auto q : queries)
  {
    string a = q[0];
    string b = q[1];
    if (graph.find(a) == graph.end() || graph.find(b) == graph.end())
    {
      ans.push_back(-1.0);
      continue;
    }
    unordered_set<string> visited;
    double res = dfs(graph, a, b, visited);
    ans.push_back(res);
  }
  return ans;
}

int main()
{
  int n, q;
  cin >> n >> q;
  vector<vector<string>> equations(n, vector<string>(2)), queries(q, vector<string>(2));
  vector<double> values(n);
  for (int i = 0; i < n; i++)
    cin >> equations[i][0] >> equations[i][1] >> values[i];
  for (int i = 0; i < q; i++)
    cin >> queries[i][0] >> queries[i][1];

  vector<double> ans = calcEquation(equations, values, queries);
  for (auto it : ans)
    cout << it << " ";
  cout << "\n";

  return 0;
}