#include <bits/stdc++.h>

using namespace std;

vector<string> topKFrequent(vector<string> &words, int k)
{
  unordered_map<string, int> mp;
  for (auto word : words)
  {
    mp[word]++;
  }
  vector<pair<string, int>> v;
  for (auto it : mp)
  {
    v.push_back({it.first, it.second});
  }
  sort(v.begin(), v.end(), [](pair<string, int> &a, pair<string, int> &b)
       {
    if (a.second == b.second)
    {
      return a.first < b.first;
    }
    return a.second > b.second; });
  vector<string> ans;
  for (int i = 0; i < k; i++)
  {
    ans.push_back(v[i].first);
  }
  return ans;
}

int main()
{
  int n, k;
  cin >> n >> k;
  vector<string> words(n);
  for (int i = 0; i < n; i++)
  {
    cin >> words[i];
  }

  vector<string> ans = topKFrequent(words, k);

  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << " ";
  }
  cout << "\n";

  return 0;
}