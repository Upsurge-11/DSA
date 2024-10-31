#include <bits/stdc++.h>

using namespace std;

int lastStoneWeight(vector<int> &stones)
{
  priority_queue<int> pq;
  for (int i = 0; i < stones.size(); i++)
    pq.push(stones[i]);
  if (pq.size() == 1)
    return pq.top();
  while (!pq.empty())
  {
    int y = pq.top();
    pq.pop();
    if (!pq.empty())
    {
      int x = pq.top();
      pq.pop();
      if (x != y)
        pq.push(y - x);
    }
    if (pq.size() == 1)
      return pq.top();
  }
  return 0;
}

int main()
{
  int n;
  cin >> n;
  vector<int> stones(n);
  for (int i = 0; i < n; i++)
    cin >> stones[i];
  cout << lastStoneWeight(stones) << "\n";
  return 0;
}