#include <bits/stdc++.h>

using namespace std;

int guess(int n)
{
}

int guessNumber(int n)
{
  int low = 1, high = n;
  int mid;
  while (low <= high)
  {
    mid = low + (high - low) / 2;
    if (guess(mid) == 0)
      return mid;
    else if (guess(mid) < 0)
      high = mid - 1;
    else
      low = mid + 1;
  }

  return mid;
}

int main()
{

  return 0;
}