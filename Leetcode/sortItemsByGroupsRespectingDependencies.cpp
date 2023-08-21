#include <bits/stdc++.h>

using namespace std;

vector<int> topoSort(vector<unordered_set<int>> &graph, vector<int> &indegree)
{
  vector<int> ans;
  queue<int> q;
  for (int i = 0; i < indegree.size(); i++)
  {
    if (indegree[i] == 0)
      q.push(i);
  }
  while (!q.empty())
  {
    int t = q.front();
    q.pop();
    ans.push_back(t);
    for (int next : graph[t])
    {
      --indegree[next];
      if (indegree[next] == 0)
        q.push(next);
    }
  }
  for (int i = 0; i < indegree.size(); i++)
  {
    if (indegree[i] > 0)
      return {};
  }
  return ans;
}

vector<int> sortItems(int n, int m, vector<int> &group, vector<vector<int>> &beforeItems)
{
  for (int i = 0; i < n; ++i)
  {
    if (group[i] == -1)
      group[i] = m++;
  }
  vector<unordered_set<int>> graphGroup(m), graphItem(n);
  vector<int> inGroup(m), inItem(n);
  for (int i = 0; i < n; i++)
  {
    int toGroup = group[i];
    for (int from : beforeItems[i])
    {
      int fromGroup = group[from];
      if (fromGroup != toGroup && !graphGroup[fromGroup].count(toGroup))
      {
        graphGroup[fromGroup].insert(toGroup);
        inGroup[toGroup]++;
      }
      if (!graphItem[from].count(i))
      {
        graphItem[from].insert(i);
        inItem[i]++;
      }
    }
  }
  vector<int> groupSorted = topoSort(graphGroup, inGroup);
  vector<int> itemSorted = topoSort(graphItem, inItem);

  if (groupSorted.empty() || itemSorted.empty())
    return {};

  vector<vector<int>> group2item(m);
  for (auto item : itemSorted)
    group2item[group[item]].push_back(item);

  vector<int> ans;
  for (int group_id : groupSorted)
  {
    for (int item : group2item[group_id])
      ans.push_back(item);
  }
  return ans;
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> group(n);
  for (int i = 0; i < n; i++)
    cin >> group[i];
  vector<vector<int>> beforeItems(n);
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    for (int j = 0; j < x; j++)
    {
      int y;
      cin >> y;
      beforeItems[i].push_back(y - 1);
    }
  }
  vector<int> ans = sortItems(n, m, group, beforeItems);
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i] << " ";
  cout << "\n";
  return 0;
}