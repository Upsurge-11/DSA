#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int countStudents(vector<int> &arr, int pages) {
  int students = 1;
  long long pagesStudent = 0;
  for (int i = 0; i < arr.size(); i++) {
    if (pagesStudent + arr[i] > pages) {
      students++;
      pagesStudent = arr[i];
    } else {
      pagesStudent += arr[i];
    }
  }
  return students;
}

int findPages(vector<int> &arr, int n, int m) {
  if (n < m)
    return -1;
  int low = *max_element(arr.begin(), arr.end()),
      high = accumulate(arr.begin(), arr.end(), 0);
  while (low <= high) {
    int mid = (low + high) / 2;
    int students = countStudents(arr, mid);
    if (students <= m)
      high = mid - 1;
    else
      low = mid + 1;
  }
  return low;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  cout << findPages(arr, n, m) << "\n";

  return 0;
}
