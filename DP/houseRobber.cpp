#include <bits/stdc++.h>

using namespace std;

int maximumAdjacentSum(vector<int> &nums)
{
  int n = nums.size();
  int prev = nums[0];
  int prev2 = 0;
  for (int i = 1; i < n; i++)
  {
    int take = nums[i];
    if (i > 1)
      take += prev2;
    int dontTake = prev;
    int curr = max(take, dontTake);
    prev2 = prev;
    prev = curr;
  }
  return prev;
}

int houseRobber(vector<int> &valuesInHouse)
{
  vector<int> temp1, temp2;
  if (valuesInHouse.size() == 1)
    return valuesInHouse[0];
  for (int i = 0; i < valuesInHouse.size(); i++)
  {
    if (i != 0)
      temp1.push_back(valuesInHouse[i]);
    else if (i != valuesInHouse.size() - 1)
      temp2.push_back(valuesInHouse[i]);
  }
  return max(maximumAdjacentSum(temp1), maximumAdjacentSum(temp2));
}

int main()
{
  int n;
  cin >> n;
  vector<int> valuesInHouse(n);
  for (int i = 0; i < n; i++)
    cin >> valuesInHouse[i];
  cout << houseRobber(valuesInHouse) << "\n";

  return 0;
}