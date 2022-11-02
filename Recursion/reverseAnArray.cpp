#include <bits/stdc++.h>

using namespace std;

// void reverseArray(vector<int> &arr, int l, int r)
// {
//   if (l >= r)
//     return;
//   swap(arr[l], arr[r]);
//   reverseArray(arr, l + 1, r - 1);
// }

void reverseArray(vector<int> &arr, int i)
{
  int n = arr.size();
  if (i >= n / 2)
    return;
  swap(arr[i], arr[n - i - 1]);
  reverseArray(arr, i + 1);
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
  // reverseArray(arr, 0, n - 1);
  reverseArray(arr, 0);

  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << "\n";

  return 0;
}