#include <bits/stdc++.h>

using namespace std;

vector<int> dailyTemperatures(vector<int> &temperatures)
{
  vector<int> ans(temperatures.size(), 0);
  stack<int> s;
  for (int i = 0; i < temperatures.size(); i++)
  {
    while (!s.empty() && temperatures[i] > temperatures[s.top()])
    {
      ans[s.top()] = i - s.top();
      s.pop();
    }
    s.push(i);
  }
  return ans;
}

int main()
{
  int n;
  cin >> n;
  vector<int> temperatures(n);
  for (int i = 0; i < n; i++)
  {
    cin >> temperatures[i];
  }
  vector<int> ans = dailyTemperatures(temperatures);
  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << " ";
  }
  cout << "\n";

  return 0;
}