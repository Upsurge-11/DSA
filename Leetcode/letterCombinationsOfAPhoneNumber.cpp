#include <bits/stdc++.h>

using namespace std;

void makeCombinations(string digits, string &currString, int i, vector<string> &ans, map<int, string> &m)
{

  if (i == digits.size())
  {
    ans.push_back(currString);
    return;
  }

  for (auto letter : m[digits[i] - '0'])
  {
    currString.push_back(letter);
    makeCombinations(digits, currString, i + 1, ans, m);
    currString.pop_back();
  }
  return;
}

vector<string> letterCombinations(string digits)
{
  if (digits == "")
    return {};

  map<int, string> m;
  m[2] = "abc";
  m[3] = "def";
  m[4] = "ghi";
  m[5] = "jkl";
  m[6] = "mno";
  m[7] = "pqrs";
  m[8] = "tuv";
  m[9] = "wxyz";

  vector<string> ans;
  string currString = "";
  makeCombinations(digits, currString, 0, ans, m);
  return ans;
}

int main()
{
  string digits;
  cin >> digits;
  vector<string> ans = letterCombinations(digits);
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i] << endl;
  cout << "\n";
  return 0;
}