#include <bits/stdc++.h>

using namespace std;

class UndergroundSystem
{
private:
  unordered_map<int, pair<string, int>> checkInStation;
  unordered_map<string, pair<int, int>> checkOutStation;

public:
  UndergroundSystem()
  {
  }

  void checkIn(int id, string stationName, int t)
  {
    checkInStation[id] = {stationName, t};
  }

  void checkOut(int id, string stationName, int t)
  {
    pair<string, int> checkIn = checkInStation[id];
    checkInStation.erase(id);
    string route = checkIn.first + "-" + stationName;
    checkOutStation[route].first += t - checkIn.second;
    checkOutStation[route].second += 1;
  }

  double getAverageTime(string startStation, string endStation)
  {
    string route = startStation + "-" + endStation;
    pair<int, int> time = checkOutStation[route];
    return (double)time.first / time.second;
  }
};

int main()
{

  return 0;
}