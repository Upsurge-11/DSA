#include <bits/stdc++.h>

using namespace std;

vector<int> answerQueries(vector<int> &nums, vector<int> &queries)
{
  vector<int> ans;
  sort(nums.begin(), nums.end());
  for (int i = 0; i < queries.size(); i++)
  {
    int count = 0, sum = 0;
    for (int j = 0; j < nums.size(); j++)
    {
      if (sum + nums[j] > queries[i])
        break;
      sum += nums[j];
      count++;
    }
    ans.push_back(count);
  }
  return ans;
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> nums(n), queries(m);
  for (int i = 0; i < n; i++)
    cin >> nums[i];

  for (int i = 0; i < m; i++)
    cin >> queries[i];

  vector<int> answer = answerQueries(nums, queries);

  return 0;
}