#include <bits/stdc++.h>

using namespace std;

string countAndSay(int n)
{
  if (n == 1)
  {
    return "1";
  }
  string str = countAndSay(n - 1);
  string ans = "";
  int count = 1;
  for (int i = 0; i < str.length(); i++)
  {
    if (str[i] == str[i + 1])
    {
      count++;
    }
    else
    {
      ans += to_string(count) + str[i];
      count = 1;
    }
  }
  return ans;
}

int main()
{
  int n;
  cin >> n;
  cout << countAndSay(n) << "\n";

  return 0;
}