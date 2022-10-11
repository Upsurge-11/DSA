#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(int x)
{
  if (x < 0)
    return false;
  int temp = x;
  long long rev = 0;
  while (temp != 0)
  {
    rev = (rev * 10) + (temp % 10);
    temp /= 10;
  }
  return rev == x;
}

int main()
{

  return 0;
}