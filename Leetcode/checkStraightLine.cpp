#include <bits/stdc++.h>

using namespace std;

bool checkStraightLine(vector<vector<int>> &coordinates) {
  if (coordinates.size() == 2)
    return true;
  int x1 = coordinates[0][0], y1 = coordinates[0][1];
  int x2 = coordinates[1][0], y2 = coordinates[1][1];
  int dx = x2 - x1, dy = y2 - y1;
  for (int i = 2; i < coordinates.size(); i++) {
    int x = coordinates[i][0], y = coordinates[i][1];
    if (dx * (y - y2) != dy * (x - x2))
      return false;
  }
  return true;
}

int main() {
  int n;
  cin >> n;
  vector<vector<int>> coordinates(n, vector<int>(2));
  for (int i = 0; i < n; i++)
    cin >> coordinates[i][0] >> coordinates[i][1];
  cout << checkStraightLine(coordinates) << "\n";

  return 0;
}
