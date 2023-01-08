#include <bits/stdc++.h>

using namespace std;

int maxPoints(vector<vector<int>> &points)
{
  int n = points.size();
  if (n <= 2)
    return n;

  int maxPoints = 0;
  for (int i = 0; i < n; i++)
  {
    int samePoints = 1;
    int verticalPoints = 0;
    int currMax = 0;
    unordered_map<double, int> slopeCount;
    for (int j = i + 1; j < n; j++)
    {
      if (points[i][0] == points[j][0] && points[i][1] == points[j][1])
        samePoints++;
      else if (points[i][0] == points[j][0])
        verticalPoints++;
      else
      {
        double slope = (double)(points[i][1] - points[j][1]) / (points[i][0] - points[j][0]);
        slopeCount[slope]++;
        currMax = max(currMax, slopeCount[slope]);
      }
      currMax = max(currMax, verticalPoints);
    }
    maxPoints = max(maxPoints, currMax + samePoints);
  }
  return maxPoints;
}

int main()
{
  int n;
  cin >> n;
  vector<vector<int>> points(n, vector<int>(2));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < 2; j++)
      cin >> points[i][j];
  }

  cout << maxPoints(points) << "\n";

  return 0;
}