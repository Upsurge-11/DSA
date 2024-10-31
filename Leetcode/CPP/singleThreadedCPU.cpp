#include <bits/stdc++.h>

using namespace std;

vector<int> getOrder(vector<vector<int>> &tasks)
{
  long n = tasks.size();
  vector<int> ans;
  for (int i = 0; i < n; i++)
  {
    tasks[i].push_back(i);
  }

  sort(tasks.begin(), tasks.end());

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minH;

  long time = 0;
  long idx = 0;

  while (idx < n || !minH.empty())
  {
    if (minH.empty())
    {
      time = max(time, (long)tasks[idx][0]);
    }
    while (idx < n && time >= tasks[idx][0])
    {
      minH.push({tasks[idx][1], tasks[idx][2]});
      idx++;
    }
    pair<int, int> currTask = minH.top();
    minH.pop();
    time = time + currTask.first;
    ans.push_back(currTask.second);
  }
  return ans;
}

int main()
{
  int n;
  cin >> n;
  vector<vector<int>> tasks(n, vector<int>(2));
  for (int i = 0; i < tasks.size(); i++)
  {
    for (int j = 0; j < 2; j++)
      cin >> tasks[i][j];
  }

  vector<int> order = getOrder(tasks);

  for (int i = 0; i < n; i++)
  {
    cout << order[i] << " ";
  }
  cout << "\n";

  return 0;
}