#include <bits/stdc++.h>

using namespace std;

bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
{
  stack<int> s;
  int i = 0;
  for (int x : pushed)
  {
    s.push(x);
    while (!s.empty() && s.top() == popped[i])
    {
      s.pop();
      i++;
    }
  }
  return s.empty();
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> pushed(n), popped(m);
  for (int i = 0; i < n; i++)
    cin >> pushed[i];
  for (int i = 0; i < m; i++)
    cin >> popped[i];
  cout << validateStackSequences(pushed, popped) << "\n";
  return 0;
}