#include <bits/stdc++.h>

using namespace std;

class MyCalendar
{
  vector<pair<int, int>> booking;

public:
  MyCalendar() {}
  bool book(int start, int end)
  {
    for (pair<int, int> x : booking)
    {
      if (max(x.first, start) < min(end, x.second))
      {
        return false;
      }
    }
    booking.push_back({start, end});
    return true;
  }
};

int main()
{

  return 0;
}