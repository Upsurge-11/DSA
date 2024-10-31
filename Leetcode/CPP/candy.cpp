#include <bits/stdc++.h>

using namespace std;

int candy(vector<int> &ratings)
{
  int size = ratings.size();
  if (size <= 1)
    return size;
  vector<int> candies(size, 1);
  for (int i = 1; i < size; i++)
  {
    if (ratings[i] > ratings[i - 1])
      candies[i] = candies[i - 1] + 1;
  }
  for (int i = size - 2; i >= 0; i--)
  {
    if (ratings[i] > ratings[i + 1])
      candies[i] = max(candies[i], candies[i + 1] + 1);
  }
  int sum = 0;
  for (int i = 0; i < size; i++)
    sum += candies[i];
  return sum;
}

int main()
{
  int n;
  cin >> n;
  vector<int> ratings(n);
  for (int i = 0; i < n; i++)
    cin >> ratings[i];
  cout << candy(ratings) << "\n";
  return 0;
}