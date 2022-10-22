#include <bits/stdc++.h>

using namespace std;

string intToRoman(int num)
{
  string roman;
  int i = 0;
  int n = num;
  int a[4];
  while (n > 0)
  {
    a[i] = n % 10;
    n /= 10;
    i++;
  }
  for (int j = i - 1; j >= 0; j--)
  {
    if (j == 3)
    {
      for (int k = 0; k < a[j]; k++)
      {
        roman += "M";
      }
    }
    else if (j == 2)
    {
      if (a[j] == 9)
      {
        roman += "CM";
      }
      else if (a[j] >= 5)
      {
        roman += "D";
        for (int k = 0; k < a[j] - 5; k++)
        {
          roman += "C";
        }
      }
      else if (a[j] == 4)
      {
        roman += "CD";
      }
      else
      {
        for (int k = 0; k < a[j]; k++)
        {
          roman += "C";
        }
      }
    }
    else if (j == 1)
    {
      if (a[j] == 9)
      {
        roman += "XC";
      }
      else if (a[j] >= 5)
      {
        roman += "L";
        for (int k = 0; k < a[j] - 5; k++)
        {
          roman += "X";
        }
      }
      else if (a[j] == 4)
      {
        roman += "XL";
      }
      else
      {
        for (int k = 0; k < a[j]; k++)
        {
          roman += "X";
        }
      }
    }
    else
    {
      if (a[j] == 9)
      {
        roman += "IX";
      }
      else if (a[j] >= 5)
      {
        roman += "V";
        for (int k = 0; k < a[j] - 5; k++)
        {
          roman += "I";
        }
      }
      else if (a[j] == 4)
      {
        roman += "IV";
      }
      else
      {
        for (int k = 0; k < a[j]; k++)
        {
          roman += "I";
        }
      }
    }
  }
  return roman;
}

int main()
{
  int num;
  cin >> num;
  cout << intToRoman(num) << "\n";

  return 0;
}