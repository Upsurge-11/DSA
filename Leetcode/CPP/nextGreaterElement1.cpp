#include <bits/stdc++.h>

using namespace std;

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
  stack<int> st;
  unordered_map<int, int> mp;
  for (auto n : nums2)
  {
    while (st.size() && st.top() < n)
    {
      mp[st.top()] = n;
      st.pop();
    }
    st.push(n);
  }
  vector<int> ans;
  for (int n : nums1)
    ans.push_back(mp.count(n) ? mp[n] : -1);
  return ans;
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> nums1(n), nums2(m);
  for (int i = 0; i < n; i++)
    cin >> nums1[i];
  for (int i = 0; i < m; i++)
    cin >> nums2[i];
  return 0;
}