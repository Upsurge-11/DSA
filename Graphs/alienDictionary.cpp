#include <bits/stdc++.h>

using namespace std;

vector<int> topoSort(int V, vector<int> adj[])
{
  vector<int> ans;
  vector<int> indegree(V, 0);
  for (int i = 0; i < V; i++)
    for (auto it : adj[i])
      indegree[it]++;
  queue<int> q;
  for (int i = 0; i < V; i++)
  {
    if (!indegree[i])
      q.push(i);
  }
  while (!q.empty())
  {
    int node = q.front();
    q.pop();
    ans.push_back(node);
    for (auto it : adj[node])
    {
      indegree[it]--;
      if (!indegree[it])
        q.push(it);
    }
  }
  return ans;
}

string findOrder(vector<string> dict, int numAlpha)
{
  vector<int> adj[numAlpha];
  for (int i = 0; i < dict.size() - 1; i++)
  {
    string s1 = dict[i];
    string s2 = dict[i + 1];
    int len = min(s1.size(), s2.size());
    for (int j = 0; j < len; j++)
    {
      if (s1[j] != s2[j])
        adj[s1[j] - 'a'].push_back(s2[j] - 'a');
    }
  }
  vector<int> topo = topoSort(numAlpha, adj);
  string ans = "";
  for (int i = 0; i < numAlpha; i++)
    ans += ans + char('a' + topo[i]);
  return ans;
}

int main()
{
  int numAlpha, x;
  cin >> numAlpha >> x;
  vector<string> dict(x);
  for (int i = 0; i < x; i++)
    cin >> dict[i];
  cout << findOrder(dict, numAlpha) << "\n";

  return 0;
}