#include <bits/stdc++.h>

using namespace std;

void print(vector<int> &arr)
{
  if (arr.size() == 0)
  {
    cout << "{}\n";
    return;
  }
  for (int i = 0; i < arr.size(); i++)
  {
    cout << arr[i] << " ";
  }
  cout << "\n";
}

bool printUtil(int index, vector<int> arr, vector<int> &ans, int k, int sum)
{
  if (index < 0 || index >= arr.size())
  {
    if (sum == k)
    {
      print(ans);
      return true;
    }
    return false;
  }
  ans.push_back(arr[index]);
  sum += arr[index];
  if (printUtil(index + 1, arr, ans, k, sum) == true)
  {
    return true;
  }
  ans.pop_back();
  sum -= arr[index];
  if (printUtil(index + 1, arr, ans, k, sum) == true)
  {
    return true;
  }
  return false;
}

void printSubsequence(vector<int> arr, int k)
{
  vector<int> help;
  printUtil(0, arr, help, k, 0);
}

int main()
{
  int n, k;
  cin >> n >> k;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  printSubsequence(arr, k);

  return 0;
}