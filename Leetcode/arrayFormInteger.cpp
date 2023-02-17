#include <bits/stdc++.h>

using namespace std;

vector<int> addToArrayForm(vector<int> &num, int k)
{
  vector<int> ans;
  int carry = 0;
  for (int i = num.size() - 1; i >= 0; --i)
  {
    int sum = num[i] + k % 10 + carry;
    ans.push_back(sum % 10);
    carry = sum / 10;
    k /= 10;
  }
  while (k > 0 || carry > 0)
  {
    int sum = k % 10 + carry;
    ans.push_back(sum % 10);
    carry = sum / 10;
    k /= 10;
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

int main()
{
  int n, k;
  cin >> n >> k;
  vector<int> num(n);
  for (int i = 0; i < n; i++)
    cin >> num[i];
  vector<int> ans = addToArrayForm(num, k);

  for (int i = 0; i < ans.size(); i++)
    cout << ans[i] << " ";
  cout << "\n";

  return 0;
}