#include <bits/stdc++.h>

using namespace std;

vector<string> findAllConcatenatedWordsInADict(vector<string> &words)
{
  unordered_set<string> words_set;
  for (string word : words)
    words_set.insert(word);
  vector<string> res;

  for (string word : words)
  {
    int n = word.size();
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
      if (!dp[i])
        continue;
      for (int j = i + 1; j <= n; j++)
      {
        if (j - i < n && words_set.count(word.substr(i, j - i)))
        {
          dp[j] = 1;
        }
      }
      if (dp[n])
      {
        res.push_back(word);
        break;
      }
    }
  }
  return res;
}

int main()
{
  int n;
  cin >> n;
  vector<string> words(n);
  for (int i = 0; i < n; i++)
    cin >> words[i];
  vector<string> ans = findAllConcatenatedWordsInADict(words);
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i] << " ";
  cout << "\n";

  return 0;
}