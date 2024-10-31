#include <bits/stdc++.h>

using namespace std;

bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
  int count = 0;
  vector<int> adj[numCourses];
  for (auto it : prerequisites)
    adj[it[0]].push_back(it[1]);
  vector<int> indegree(numCourses, 0);
  for (int i = 0; i < numCourses; i++)
  {
    for (auto it : adj[i])
      indegree[it]++;
  }
  queue<int> q;
  for (int i = 0; i < numCourses; i++)
  {
    if (!indegree[i])
      q.push(i);
  }
  while (!q.empty())
  {
    int node = q.front();
    q.pop();
    count++;
    for (auto it : adj[node])
    {
      indegree[it]--;
      if (!indegree[it])
        q.push(it);
    }
  }
  return (count == numCourses);
}

int main()
{
  int numCourses;
  cin >> numCourses;
  vector<vector<int>> prerequisites(numCourses);
  for (int i = 0; i < numCourses; i++)
  {
    int n;
    cin >> n;
    for (int j = 0; j < n; j++)
    {
      int x;
      cin >> x;
      prerequisites[i].push_back(x);
    }
  }
  cout << (canFinish(numCourses, prerequisites) ? "YES" : "NO") << "\n";

  return 0;
}