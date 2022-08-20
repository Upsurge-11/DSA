// Given an integer array nums, handle multiple queries of the following types:
// 1. Update the value of an element in nums.
// 2. Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.

#include <bits/stdc++.h>

using namespace std;

// class NumArray
// {
//   vector<int> num;
//   vector<int> sumArray;

// public:
//   NumArray(vector<int> &nums)
//   {
//     num = nums;
//     sumArray.resize(num.size());
//     sumArray[0] = num[0];
//     for (int i = 1; i < sumArray.size(); i++)
//     {
//       sumArray[i] = nums[i] + sumArray[i - 1];
//     }
//   }
//   NumArray() {}
//   void update(int index, int value)
//   {
//     num[index] = value;
//     if (index != 0)
//       sumArray[index] = sumArray[index - 1] + value;
//     else
//       sumArray[index] = value;
//     for (int i = index + 1; i < sumArray.size(); i++)
//     {
//       sumArray[i] = num[i] + sumArray[i - 1];
//     }
//   }
//   int sumRange(int left, int right)
//   {
//     if (left == 0)
//       return sumArray[right];
//     return sumArray[right] - sumArray[left - 1];
//   }
// };

class NumArray
{
  vector<int> num;
  int sum;

public:
  NumArray(vector<int> &nums)
  {
    num = nums;
    sum = 0;
    for (int i = 0; i < num.size(); i++)
    {
      sum += num[i];
    }
  }
  void update(int index, int value)
  {
    sum -= num[index];
    num[index] = value;
    sum += value;
  }
  int sumRange(int left, int right)
  {
    int ans = sum;
    for (int i = 0; i < left; i++)
    {
      ans -= num[i];
    }
    for (int i = right + 1; i < num.size(); i++)
    {
      ans -= num[i];
    }
    return ans;
  }
};

int main()
{
  int n;
  cin >> n;
  vector<int> nums(n);
  for (auto &i : nums)
  {
    cin >> i;
  }
  NumArray *obj = new NumArray(nums);
  int index, val;
  cin >> index >> val;
  obj->update(index, val);
  int left, right;
  cin >> left >> right;
  int param_2 = obj->sumRange(left, right);
  cout << param_2 << "\n";
  return 0;
}