#include <bits/stdc++.h>

using namespace std;

int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
{
  int n = profits.size();
  vector<pair<int, int>> projects(n);
  for (int i = 0; i < n; i++)
    projects[i] = {capital[i], profits[i]};
  sort(projects.begin(), projects.end());
  int i = 0;
  priority_queue<int> maximizeCapital;
  while (k--)
  {
    while (i < n && projects[i].first <= w)
    {
      maximizeCapital.push(projects[i].second);
      i++;
    }
    if (maximizeCapital.empty())
      break;
    w += maximizeCapital.top();
    maximizeCapital.pop();
  }
  return w;
}

int main()
{
  int n, k, w;
  cin >> n >> k >> w;
  vector<int> profits(n), capital(n);

  cout << findMaximizedCapital(k, w, profits, capital) << "\n";

  return 0;
}