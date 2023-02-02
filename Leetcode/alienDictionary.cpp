#include <bits/stdc++.h>

using namespace std;

bool isAlienSorted(vector<string> &words, string order)
{
  unordered_map<char, int> map;
  for (int i = 0; i < order.length(); i++)
  {
    map[order[i]] = i;
  }
  for (int i = 1; i < words.size(); i++)
  {
    string word1 = words[i - 1];
    string word2 = words[i];
    int n = min(word1.length(), word2.length());
    bool flag = false;
    for (int j = 0; j < n; j++)
    {
      if (map[word1[j]] < map[word2[j]])
      {
        flag = true;
        break;
      }
      else if (map[word1[j]] > map[word2[j]])
      {
        return false;
      }
    }
    if (!flag && word1.length() > word2.length())
    {
      return false;
    }
  }
  return true;
}

int main()
{
  int n;
  cin >> n;
  vector<string> words(n);
  for (int i = 0; i < n; i++)
    cin >> words[i];

  string order;
  cin >> order;

  if (isAlienSorted(words, order))
    cout << "Sorted\n";
  else
    cout << "Not Sorted\n";

  return 0;
}