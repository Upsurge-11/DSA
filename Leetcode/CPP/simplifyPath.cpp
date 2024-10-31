#include <bits/stdc++.h>

using namespace std;

string simplifyPath(string path)
{
  vector<string> v;
  string temp;
  for (int i = 0; i < path.size(); i++)
  {
    if (path[i] == '/')
    {
      if (temp == "..")
      {
        if (!v.empty())
          v.pop_back();
      }
      else if (temp != "." && temp != "")
        v.push_back(temp);
      temp = "";
    }
    else
      temp += path[i];
  }
  if (temp == "..")
  {
    if (!v.empty())
      v.pop_back();
  }
  else if (temp != "." && temp != "")
    v.push_back(temp);
  string ans = "";
  for (int i = 0; i < v.size(); i++)
    ans += "/" + v[i];
  if (ans == "")
    ans = "/";
  return ans;
}

int main()
{
  string path;
  cin >> path;
  cout << simplifyPath(path) << "\n";
  return 0;
}