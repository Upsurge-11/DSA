#include <bits/stdc++.h>

using namespace std;

bool palindrome(string str, int i)
{
  int n = str.size();
  if (i >= n / 2)
    return true;
  return (str[i] == str[n - i - 1]) && palindrome(str, i + 1);
}

int main()
{
  string str;
  cin >> str;
  if (palindrome(str, 0))
  {
    cout << "Palindrome.\n";
  }
  else
  {
    cout << "Not Palindrome.\n";
  }

  return 0;
}