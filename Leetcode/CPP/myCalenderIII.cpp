#include <bits/stdc++.h>

using namespace std;

class MyCalendarThree
{
  map<int, int> m;

public:
  MyCalendarThree()
  {
  }

  int book(int start, int end)
  {
    ++m[start];
    --m[end];
    int res = 0, cur = 0;
    for (auto &p : m)
    {
      cur += p.second;
      res = max(res, cur);
    }
    return res;
  }
};

int main()
{

  return 0;
}