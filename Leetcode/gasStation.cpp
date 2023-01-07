#include <bits/stdc++.h>

using namespace std;

int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
  int n = gas.size();
  int start = 0;
  int end = 1;
  int curr = gas[start] - cost[start];

  if (n == 1)
    return (curr >= 0 ? 0 : -1);

  while (start != end || curr < 0)
  {
    while (curr < 0 && start != end)
    {
      curr -= gas[start] - cost[start];
      start = (start + 1) % n;
      if (start == 0)
        return -1;
    }
    curr += gas[end] - cost[end];
    end = (end + 1) % n;
  }
  return start;
}

int main()
{
  int n;
  cin >> n;
  vector<int> gas(n), cost(n);
  for (int i = 0; i < n; i++)
  {
    cin >> gas[i];
    cin >> cost[i];
  }

  cout << canCompleteCircuit(gas, cost) << "\n";

  return 0;
}