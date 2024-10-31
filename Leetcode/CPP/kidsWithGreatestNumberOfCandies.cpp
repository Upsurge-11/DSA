#include <bits/stdc++.h>

using namespace std;

vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
{
  vector<bool> ans;
  int maxi = candies[0];
  for (int i = 1; i < candies.size(); i++)
    maxi = max(candies[i], maxi);
  for (int i = 0; i < candies.size(); i++)
  {
    if (candies[i] + extraCandies >= maxi)
      ans.push_back(true);
    else
      ans.push_back(false);
  }
  return ans;
}

int main()
{
  int n;
  cin >> n;
  vector<int> candies(n);
  for (int i = 0; i < n; i++)
    cin >> candies[i];
  int extraCandies;
  cin >> extraCandies;
  vector<bool> ans = kidsWithCandies(candies, extraCandies);
  for (int i = 0; i < ans.size(); i++)
    cout << (ans[i] ? "Yes" : "No") << endl;

  return 0;
}