#include <bits/stdc++.h>

using namespace std;

int minJumps(vector<int> &arr)
{
  int n = arr.size();
  if (n == 1)
    return 0;
  unordered_map<int, vector<int>> ind;
  for (int i = 0; i < n; i++)
    ind[arr[i]].push_back(i);
  queue<int> storeInd;
  vector<bool> vis(n);
  storeInd.push(0);
  vis[0] = true;
  int steps = 0;
  while (!storeInd.empty())
  {
    int size = storeInd.size();
    while (size--)
    {
      int currIndex = storeInd.front();
      storeInd.pop();
      if (currIndex == n - 1)
        return steps;
      vector<int> &jumpNextIndices = ind[arr[currIndex]];
      jumpNextIndices.push_back(currIndex - 1);
      jumpNextIndices.push_back(currIndex + 1);
      for (int jumpNextIndex : jumpNextIndices)
      {
        if (jumpNextIndex >= 0 && jumpNextIndex < n && !vis[jumpNextIndex])
        {
          storeInd.push(jumpNextIndex);
          vis[jumpNextIndex] = true;
        }
      }
      jumpNextIndices.clear();
    }
    steps++;
  }
  return -1;
}

int main()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  cout << minJumps(arr) << "\n";

  return 0;
}