#include <bits/stdc++.h>

using namespace std;

char nextGreatestLetter(vector<char> &letters, char target) {
  int n = letters.size();
  int left = 0, right = n - 1;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (letters[mid] <= target)
      left = mid + 1;
    else
      right = mid - 1;
  }
  return letters[left % n];
}

int main() {
  int n;
  cin >> n;
  vector<char> letters(n);
  for (int i = 0; i < n; i++)
    cin >> letters[i];
  char target;
  cin >> target;
  cout << nextGreatestLetter(letters, target) << "\n";
  return 0;
}
