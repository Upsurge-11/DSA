#include <bits/stdc++.h>

using namespace std;

vector<int> countBits(int n)
{
  vector<int> ans;
  for (int i = 0; i <= n; i++)
  {
    int sum = 0;
    int num = i;
    while (num)
    {
      sum += num % 2;
      num /= 2;
    }
    ans.push_back(sum);
  }
  return ans;
}

int main()
{
  int n;
  cin >> n;
  vector<int> ans = countBits(n);
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i] << " ";
  cout << "\n";
  return 0;
}