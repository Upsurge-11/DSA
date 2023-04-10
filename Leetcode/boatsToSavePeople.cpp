#include <bits/stdc++.h>

using namespace std;

int numRescueBoats(vector<int> &people, int limit)
{
  int ans = 0;
  sort(people.begin(), people.end());
  int l = 0, r = people.size() - 1;
  while (l <= r)
  {
    if (people[l] + people[r] <= limit)
    {
      ans++;
      l++;
      r--;
    }
    else
    {
      ans++;
      r--;
    }
  }
  return ans;
}

int main()
{
  int n, limit;
  cin >> n >> limit;
  vector<int> people(n);
  for (int i = 0; i < n; i++)
    cin >> people[i];
  cout << numRescueBoats(people, limit) << "\n";
  return 0;
}