#include <bits/stdc++.h>

using namespace std;

int bestClosingTime(string customers)
{
  int maxSum = 0, score = 0, bestHour = -1;
  for (int i = 0; i < customers.size(); ++i)
  {
    score += (customers[i] == 'Y') ? 1 : -1;
    if (score > maxSum)
    {
      maxSum = score;
      bestHour = i;
    }
  }
  return bestHour + 1;
}

int main()
{
  string s;
  cin >> s;
  cout << bestClosingTime(s) << "\n";
  return 0;
}