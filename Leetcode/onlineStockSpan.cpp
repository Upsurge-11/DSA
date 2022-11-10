#include <bits/stdc++.h>

using namespace std;

class StockSpanner
{
public:
  stack<pair<int, int>> s;
  int i = 0;
  StockSpanner()
  {
  }

  int next(int price)
  {
    while (!s.empty() && s.top().first <= price)
    {
      s.pop();
    }
    int ans = s.empty() ? i + 1 : i - s.top().second;
    s.push({price, i});
    i++;
    return ans;
  }
};

int main()
{

  return 0;
}