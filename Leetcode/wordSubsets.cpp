#include <bits/stdc++.h>

using namespace std;

vector<int> frequencyArray(string s)
{
  vector<int> freq(26, 0);
  for (int i = 0; i < s.size(); i++)
  {
    freq[s[i] - 'a']++;
  }
  return freq;
}

vector<string> wordSubsets(vector<string> &words1, vector<string> &words2)
{
  vector<string> ans;
  vector<int> freq2(26, 0);

  for (int i = 0; i < words2.size(); i++)
  {
    vector<int> temp = frequencyArray(words2[i]);
    for (int j = 0; j < 26; j++)
    {
      freq2[j] = max(freq2[j], temp[j]);
    }
  }

  for (int i = 0; i < words1.size(); i++)
  {
    vector<int> freq1 = frequencyArray(words1[i]);
    bool check = true;
    for (int j = 0; j < 26; j++)
    {
      if (freq1[j] < freq2[j])
      {
        check = false;
        break;
      }
    }
    if (check)
    {
      ans.push_back(words1[i]);
    }
  }

  return ans;
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<string> words1(n);
  vector<string> words2(m);
  for (auto &i : words1)
  {
    cin >> i;
  }
  for (auto &i : words2)
  {
    cin >> i;
  }
  vector<string> ans = wordSubsets(words1, words2);
  for (auto &i : ans)
  {
    cout << i << " ";
  }
  cout << "\n";

  return 0;
}