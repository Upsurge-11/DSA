#include <bits/stdc++.h>

using namespace std;

int minStoneSum(vector<int> &piles, int k)
{
  priority_queue<int> pq(piles.begin(), piles.end());
  while (k--)
  {
    int n = pq.top();
    pq.pop();
    n -= floor(n / 2);
    pq.push(n);
  }
  int sum = 0;
  while (!pq.empty())
  {
    sum += pq.top();
    pq.pop();
  }
  return sum;
}

int main()
{
  int n, k;
  cin >> n >> k;

  vector<int> piles(n);

  for (int i = 0; i < n; i++)
    cin >> piles[i];

  cout << minStoneSum(piles, k);

  return 0;
}