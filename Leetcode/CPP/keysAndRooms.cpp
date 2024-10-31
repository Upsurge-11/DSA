#include <bits/stdc++.h>

using namespace std;

bool canVisitAllRooms(vector<vector<int>> &rooms)
{
  int n = rooms.size();
  vector<bool> visited(n, false);
  queue<int> q;
  q.push(0);
  visited[0] = true;
  while (!q.empty())
  {
    int curr = q.front();
    q.pop();
    for (int i = 0; i < rooms[curr].size(); i++)
    {
      if (!visited[rooms[curr][i]])
      {
        q.push(rooms[curr][i]);
        visited[rooms[curr][i]] = true;
      }
    }
  }
  for (int i = 0; i < n; i++)
  {
    if (!visited[i])
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
  vector<vector<int>> rooms(n);

  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    vector<int> temp(x);
    for (int j = 0; j < x; j++)
    {
      cin >> temp[j];
    }
    rooms[i] = temp;
  }

  if (canVisitAllRooms)
  {
    cout << "Can visit all the rooms.\n";
  }
  else
  {
    cout << "Can't visit all the rooms.\n";
  }

  return 0;
}