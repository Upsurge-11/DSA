#include <bits/stdc++.h>

using namespace std;

int largestRectangleArea(vector<int> &heights)
{
  int n = heights.size(), ans = 0;
  stack<int> st;
  vector<int> leftsmall(n), rightsmall(n);
  for (int i = 0; i < n; i++)
  {
    while (!st.empty() && heights[st.top()] >= heights[i])
      st.pop();
    if (st.empty())
      leftsmall[i] = 0;
    else
      leftsmall[i] = st.top() + 1;
    st.push(i);
  }
  while (!st.empty())
    st.pop();

  for (int i = n - 1; i >= 0; i--)
  {
    while (!st.empty() && heights[st.top()] >= heights[i])
      st.pop();

    if (st.empty())
      rightsmall[i] = n - 1;
    else
      rightsmall[i] = st.top() - 1;
    ans = max(ans, heights[i] * (rightsmall[i] - leftsmall[i] + 1));
    st.push(i);
  }
  return ans;
}

int main()
{
  int n;
  cin >> n;
  vector<int> heights(n);
  for (int i = 0; i < n; i++)
    cin >> heights[i];
  cout << largestRectangleArea(heights) << "\n";
  return 0;
}