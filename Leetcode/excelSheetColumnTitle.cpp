#include <bits/stdc++.h>

using namespace std;

string convertToTitle(int columnNumber)
{
  string ans = "";
  while (columnNumber)
  {
    columnNumber--;
    int curr = columnNumber % 26;
    columnNumber /= 26;
    ans.push_back('A' + curr);
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

int main()
{
  int columnNumber;
  cin >> columnNumber;
  cout << convertToTitle(columnNumber) << "\n";
  return 0;
}