#include <bits/stdc++.h>

using namespace std;

void dfs(const vector<vector<int>> &graph, int node, vector<int> &temp, vector<vector<int>> &ans)
{
  temp.push_back(node);
  if (node == graph.size() - 1)
  {
    ans.push_back(temp);
  }
  else
  {
    for (int i = 0; i < graph[node].size(); i++)
    {
      dfs(graph, graph[node][i], temp, ans);
    }
  }
  temp.pop_back();
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
{
  vector<vector<int>> ans;
  for (int i = 0; i < graph[0].size(); i++)
  {
    vector<int> temp;
    temp.push_back(0);
    dfs(graph, graph[0][i], temp, ans);
  }
  return ans;
}

int main()
{
  int n;
  cin >> n;
  vector<vector<int>> graph(n);

  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    vector<int> temp(x);
    for (int j = 0; j < x; j++)
    {
      cin >> temp[j];
    }
    graph[i] = temp;
  }

  vector<vector<int>> ans = allPathsSourceTarget(graph);

  for (int i = 0; i < ans.size(); i++)
  {
    for (int j = 0; j < ans[i].size(); j++)
      cout << ans[i][j];
    cout << "\n";
  }

  return 0;
}