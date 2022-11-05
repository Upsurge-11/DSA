#include <bits/stdc++.h>

using namespace std;

struct TrieNode
{
  TrieNode *children[26];
  string word;

  TrieNode() : word("")
  {
    for (int i = 0; i < 26; i++)
    {
      children[i] = nullptr;
    }
  }
};

void dfs(vector<vector<char>> &board, int i, int j, TrieNode *p, vector<string> &result)
{
  char c = board[i][j];
  if (c == '#' || !p->children[c - 'a'])
    return;
  p = p->children[c - 'a'];
  if (p->word.size() > 0)
  {
    result.push_back(p->word);
    p->word = "";
  }

  board[i][j] = '#';
  if (i > 0)
    dfs(board, i - 1, j, p, result);
  if (j > 0)
    dfs(board, i, j - 1, p, result);
  if (i < board.size() - 1)
    dfs(board, i + 1, j, p, result);
  if (j < board[0].size() - 1)
    dfs(board, i, j + 1, p, result);
  board[i][j] = c;
}

vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
{
  vector<string> result;
  TrieNode *root = new TrieNode();
  for (string word : words)
  {
    TrieNode *node = root;
    for (char c : word)
    {
      if (node->children[c - 'a'] == nullptr)
      {
        node->children[c - 'a'] = new TrieNode();
      }
      node = node->children[c - 'a'];
    }
    node->word = word;
  }

  for (int i = 0; i < board.size(); i++)
  {
    for (int j = 0; j < board[0].size(); j++)
    {
      dfs(board, i, j, root, result);
    }
  }
  return result;
}

TrieNode *buildTrie(vector<string> &words)
{
  TrieNode *root = new TrieNode();
  for (int j = 0; j < words.size(); j++)
  {
    string word = words[j];
    TrieNode *curr = root;
    for (int i = 0; i < word.length(); i++)
    {
      char c = word[i] - 'a';
      if (curr->children[c] == nullptr)
      {
        curr->children[c] = new TrieNode();
      }
      curr = curr->children[c];
    }
    curr->word = word;
  }
  return root;
}

int main()
{
  int m, n;
  cin >> m >> n;
  vector<vector<char>> board(m, vector<char>(n));
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> board[i][j];
    }
  }

  int x;
  cin >> x;
  vector<string> words(x);

  for (int i = 0; i < x; i++)
  {
    cin >> words[i];
  }

  vector<string> ans = findWords(board, words);

  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << " ";
  }

  cout << "\n";

  return 0;
}