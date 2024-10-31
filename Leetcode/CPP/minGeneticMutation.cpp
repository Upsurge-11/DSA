#include <bits/stdc++.h>

using namespace std;

int minMutation(string start, string end, vector<string> &bank)
{
  unordered_set<string> bankSet(bank.begin(), bank.end());
  if (bankSet.find(end) == bankSet.end())
    return -1;
  unordered_set<string> visited;
  queue<string> q;
  q.push(start);
  visited.insert(start);
  int level = 0;
  while (!q.empty())
  {
    int size = q.size();
    for (int i = 0; i < size; i++)
    {
      string curr = q.front();
      q.pop();
      if (curr == end)
        return level;
      for (int j = 0; j < curr.size(); j++)
      {
        char temp = curr[j];
        for (char c : {'A', 'C', 'G', 'T'})
        {
          curr[j] = c;
          if (bankSet.find(curr) != bankSet.end() && visited.find(curr) == visited.end())
          {
            q.push(curr);
            visited.insert(curr);
          }
        }
        curr[j] = temp;
      }
    }
    level++;
  }
  return -1;
}

int main()
{
  string start, end;
  cin >> start >> end;
  int n;
  cin >> n;
  vector<string> bank(n);
  for (int i = 0; i < n; i++)
  {
    cin >> bank[i];
  }

  cout << minMutation(start, end, bank) << "\n";

  return 0;
}