#include <bits/stdc++.h>

using namespace std;

void printNames(string s, int n)
{
  if (n == 0)
    return;
  printNames(s, n - 1);
  cout << s << "\n";
}

int main()
{
  int n;
  cin >> n;
  string s;
  cin >> s;
  printNames(s, n);

  return 0;
}