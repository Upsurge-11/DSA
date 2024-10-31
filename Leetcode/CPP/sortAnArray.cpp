#include <bits/stdc++.h>

using namespace std;

void mergeArrays(vector<int> &nums, vector<int> &L, vector<int> &R)
{
  int sizeL = L.size();
  int sizeR = R.size();
  int i = 0, j = 0, k = 0;
  while (i < sizeL && j < sizeR)
  {
    if (L[i] <= R[j])
      nums[k] = L[i++];
    else
      nums[k] = R[j++];
    k++;
  }
  while (i < sizeL)
    nums[k++] = L[i++];
  while (j < sizeR)
    nums[k++] = R[j++];
}

void mergeSort(vector<int> &nums, int n)
{
  if (n < 2)
    return;
  int mid = n / 2;
  vector<int> L;
  vector<int> R;
  for (int i = 0; i < n; i++)
  {
    if (i < mid)
      L.push_back(nums[i]);
    else
      R.push_back(nums[i]);
  }
  mergeSort(L, L.size());
  mergeSort(R, R.size());
  mergeArrays(nums, L, R);
}

vector<int> sortArray(vector<int> &nums)
{
  int n = nums.size();
  mergeSort(nums, n);
  return nums;
}

int main()
{
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
    cin >> nums[i];

  vector<int> sorted = sortArray(nums);
  for (int i = 0; i < n; i++)
    cout << nums[i] << " ";
  cout << "\n";

  return 0;
}