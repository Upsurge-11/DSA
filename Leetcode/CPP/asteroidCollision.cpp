#include <bits/stdc++.h>

using namespace std;

vector<int> asteroidCollision(vector<int> &asteroids)
{
  stack<int> st;

  for (int i = 0; i < asteroids.size(); i++)
  {
    if (st.empty() || asteroids[i] > 0)
      st.push(asteroids[i]);
    else
    {
      while (!st.empty() && st.top() > 0 && st.top() < abs(asteroids[i]))
        st.pop();
      if (!st.empty() && st.top() == abs(asteroids[i]))
        st.pop();
      else
      {
        if (st.empty() || st.top() < 0)
          st.push(asteroids[i]);
      }
    }
  }
  vector<int> ans(st.size(), 0);
  int size = st.size();
  while (!st.empty())
  {
    ans[--size] = st.top();
    st.pop();
  }
  return ans;
}

int main()
{
  int n;
  cin >> n;
  vector<int> asteroids(n);
  for (int i = 0; i < n; i++)
    cin >> asteroids[i];
  vector<int> ans = asteroidCollision(asteroids);
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i] << " ";
  cout << "\n";
  return 0;
}