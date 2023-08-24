#include <bits/stdc++.h>

using namespace std;

void addSpaces(int i, int spaceCnt, int maxWidth, bool is_last, string *s)
{
  if (i < spaceCnt)
  {
    int spaces = is_last ? 1 : maxWidth / spaceCnt + (i < maxWidth % spaceCnt);
    s->append(spaces, ' ');
  }
}

string connect(const vector<string> &words, int maxWidth, int begin, int end, int len, bool is_last)
{
  string s;
  int n = end - begin;
  for (int i = 0; i < n; ++i)
  {
    s += words[begin + i];
    addSpaces(i, n - 1, maxWidth - len, is_last, &s);
  }
  if (s.size() < maxWidth)
    s.append(maxWidth - s.size(), ' ');
  return s;
}

vector<string> fullJustify(vector<string> &words, int maxWidth)
{
  vector<string> res;
  const int n = words.size();
  int begin = 0, len = 0;
  for (int i = 0; i < n; ++i)
  {
    if (len + words[i].size() + (i - begin) > maxWidth)
    {
      res.emplace_back(connect(words, maxWidth, begin, i, len, false));
      begin = i;
      len = 0;
    }
    len += words[i].size();
  }
  res.emplace_back(connect(words, maxWidth, begin, n, len, true));
  return res;
}

int main()
{
  int n, maxWidth;
  cin >> n >> maxWidth;
  vector<string> words(n);
  for (int i = 0; i < n; i++)
    cin >> words[i];
  vector<string> res = fullJustify(words, maxWidth);
  for (int i = 0; i < res.size(); i++)
    cout << res[i] << " ";
  cout << "\n";
  return 0;
}