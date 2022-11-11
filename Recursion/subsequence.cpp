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

void printUtil(int index, vector<int> arr, vector<int> &ans)
{
  if (index < 0 || index >= arr.size())
  {
    print(ans);
    return;
  }
  ans.push_back(arr[index]);
  printUtil(index + 1, arr, ans);
  ans.pop_back();
  printUtil(index + 1, arr, ans);
}

void printSubsequence(vector<int> arr)
{
  vector<int> help;
  printUtil(0, arr, help);
}

int main()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  printSubsequence(arr);

  return 0;
}