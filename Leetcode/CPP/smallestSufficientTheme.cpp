#include <bits/stdc++.h>

using namespace std;

void func(int cur, int n, vector<int> &arr, vector<int> team, vector<bool> &banned, vector<int> &ans)
{
  if (cur == (1 << n) - 1)
  {
    if (ans.empty() || team.size() < ans.size())
      ans = team;
    return;
  }
  if (!ans.empty() && team.size() >= ans.size())
    return;
  int zero = 0;
  while (((cur >> zero) & 1) == 1)
    zero++;
  for (int i = 0; i < arr.size(); i++)
  {
    if (banned[i])
      continue;
    if (((arr[i] >> zero) & 1) == 1)
    {
      team.push_back(i);
      func(cur | arr[i], n, arr, team, banned, ans);
      team.pop_back();
    }
  }
}

vector<int> smallestSufficientTeam(vector<string> &req_skills, vector<vector<string>> &people)
{
  int n = req_skills.size(), m = people.size();
  unordered_map<string, int> skillToIndex;
  for (int i = 0; i < n; i++)
    skillToIndex[req_skills[i]] = i;
  vector<int> arr(m, 0);
  for (int i = 0; i < m; i++)
  {
    vector<string> &personSkills = people[i];
    int val = 0;
    for (const string &skill : personSkills)
      val |= 1 << skillToIndex[skill];
    arr[i] = val;
  }
  vector<bool> banned(m, false);
  for (int i = 0; i < m; i++)
  {
    for (int j = i + 1; j < m; j++)
    {
      int val = arr[i] | arr[j];
      if (val == arr[i])
        banned[j] = true;
      else if (val == arr[j])
        banned[i] = true;
    }
  }
  vector<int> ans;
  func(0, n, arr, vector<int>(), banned, ans);
  return ans;
}

int main()
{
  int n, x;
  cin >> n >> x;
  vector<string> req_skills(n);
  vector<vector<string>> people(x);
  for (int i = 0; i < n; i++)
    cin >> req_skills[i];
  for (int i = 0; i < x; i++)
  {
    int y;
    cin >> y;
    for (int j = 0; j < y; j++)
      cin >> people[i][j];
  }
  vector<int> ans = smallestSufficientTeam(req_skills, people);
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i] << " ";
  cout << "\n";
  return 0;
}