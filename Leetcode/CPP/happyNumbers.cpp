#include <bits/stdc++.h>

using namespace std;

bool isHappy(int n)
{
  int temp = 0;
  while (true)
  {
    while (n > 0)
    {
      int lastDigit = n % 10;
      temp += (lastDigit * lastDigit);
      n /= 10;
    }
    if (temp == 1)
      break;
    if (temp / 10 == 0 && temp != 7)
      break;
    n = temp;
    temp = 0;
  }
  if (temp == 1)
    return true;
  return false;
}

int main()
{
  int n;
  cin >> n;
  cout << isHappy(n) << "\n";
  return 0;
}