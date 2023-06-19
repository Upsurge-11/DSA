#include <bits/stdc++.h>

using namespace std;

int largestAltitude(vector<int> &gain)
{
  vector<int> altitude(gain.size() + 1, 0);
  altitude[0] = 0;
  int ans = 0;
  for (int i = 0; i < gain.size(); i++)
  {
    altitude[i + 1] = altitude[i] + gain[i];
    ans = max(ans, altitude[i + 1]);
  }
  return ans;
}

int main()
{
  int n;
  cin >> n;
  vector<int> gain(n);
  for (int i = 0; i < n; i++)
    cin >> gain[i];
  cout << largestAltitude(gain) << "\n";

  return 0;
}