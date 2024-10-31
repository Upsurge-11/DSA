#include <bits/stdc++.h>

using namespace std;

bool uniqueOccurrences(vector<int> &arr)
{
  unordered_map<int, int> m;
  for (int i = 0; i < arr.size(); i++)
  {
    m[arr[i]]++;
  }
  unordered_set<int> s;
  for (auto i : m)
  {
    if (s.find(i.second) != s.end())
      return false;
    s.insert(i.second);
  }
  return true;
}

int main()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  if (uniqueOccurrences(arr))
  {
    cout << "True\n";
  }
  else
  {
    cout << "False\n";
  }

  return 0;
}