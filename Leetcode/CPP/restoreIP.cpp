#include <bits/stdc++.h>

using namespace std;

vector<string> restoreIpAddresses(string s)
{
  vector<string> ans;
  int n = s.size();
  for (int i = 1; i < 4 && i < n - 2; i++)
  {
    for (int j = i + 1; j < i + 4 && j < n - 1; j++)
    {
      for (int k = j + 1; k < j + 4 && k < n; k++)
      {
        string s1 = s.substr(0, i);
        string s2 = s.substr(i, j - i);
        string s3 = s.substr(j, k - j);
        string s4 = s.substr(k, n - k);

        if (s1.size() > 3 || s2.size() > 3 || s3.size() > 3 || s4.size() > 3)
          continue;

        if ((s1[0] == '0' && s1.size() > 1) || (s2[0] == '0' && s2.size() > 1) || (s3[0] == '0' && s3.size() > 1) || (s4[0] == '0' && s4.size() > 1))
          continue;

        int n1 = stoi(s1);
        int n2 = stoi(s2);
        int n3 = stoi(s3);
        int n4 = stoi(s4);

        if (n1 > 255 || n2 > 255 || n3 > 255 || n4 > 255)
          continue;

        ans.push_back(s1 + "." + s2 + "." + s3 + "." + s4);
      }
    }
  }

  return ans;
}

int main()
{
  string s;
  cin >> s;
  vector<string> ans = restoreIpAddresses(s);
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i] << "\n";

  return 0;
}