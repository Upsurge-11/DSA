// Given a list of strings words and a string pattern, return a list of words[i] that match pattern.You may return the answer in any order.
// A word matches the pattern if there exists a permutation of letters p so that after replacing every letter x in the pattern with p(x), we get the desired word.
// 6
// abc
// deq
// mee
// aqq
// dkd
// ccc
// abb

#include <bits/stdc++.h>

using namespace std;

// bool sortbysecdesc(const pair<int, int> &a, const pair<int, int> &b)
// {
//   return a.first > b.first;
// }

// vector<string> findAndReplacePattern(vector<string> &words, string pattern)
// {
//   vector<string> ans;
//   vector<pair<int, char>> freqPattern(26, {0, '!'});
//   for (int i = 0; i < pattern.size(); i++)
//   {
//     freqPattern[pattern[i] - 'a'].first++;
//     freqPattern[pattern[i] - 'a'].second = pattern[i];
//   }
//   sort(freqPattern.begin(), freqPattern.end(), sortbysecdesc);
//   for (int i = 0; i < words.size(); i++)
//   {
//     vector<pair<int, char>> freqWords(26, {0, '!'});
//     for (int j = 0; j < words[i].size(); j++)
//     {
//       freqWords[words[i][j] - 'a'].first++;
//       freqWords[words[i][j] - 'a'].second = words[i][j];
//     }
//     sort(freqWords.begin(), freqWords.end(), sortbysecdesc);
//     bool check = true;
//     for (int j = 0; j < 26; j++)
//     {
//       if (freqWords[j].first != freqPattern[j].first)
//       {
//         check = false;
//         break;
//       }
//       else if (freqWords[j].first == 0 && freqPattern[j].first == 0)
//       {
//         check = true;
//         break;
//       }
//     }
//     if (check)
//     {
//       ans.push_back(words[i]);
//     }
//   }
//   return ans;
// }

string patternStyle(string s)
{
  map<char, char> m;
  int j = 0;
  string temp;
  for (auto x : s)
  {
    if (m.find(x) == m.end())
    {
      m[x] = '1' + j;
      j++;
    }
    temp.push_back(m[x]);
  }
  return temp;
}

vector<string> findAndReplacePattern(vector<string> &words, string pattern)
{
  string s = patternStyle(pattern);
  vector<string> ans;
  for (auto x : words)
  {
    string t = patternStyle(x);
    if (s == t)
      ans.push_back(x);
  }

  return ans;
}

int main()
{
  int n;
  cin >> n;
  vector<string> words(n);
  for (int i = 0; i < n; i++)
  {
    cin >> words[i];
  }
  string pattern;
  cin >> pattern;
  vector<string> ans = findAndReplacePattern(words, pattern);
  for (auto &i : ans)
  {
    cout << i << " ";
  }

  return 0;
}