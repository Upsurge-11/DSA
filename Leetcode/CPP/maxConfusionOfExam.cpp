#include <bits/stdc++.h>

using namespace std;

int maxConsecutiveAnswers(string answerKey, int k) {
  int n = answerKey.size();
  int maxConfusion = 0;
  int left = 0, right = 0;
  int countT = 0, countF = 0;
  while (right < n) {
    if (answerKey[right] == 'T')
      countT++;
    else
      countF++;
    if (min(countT, countF) > k) {
      if (answerKey[left] == 'T')
        countT--;
      else
        countF--;
      left++;
    }
    maxConfusion = max(maxConfusion, right - left + 1);
    right++;
  }
  return maxConfusion;
}

int main() {
  int k;
  string answerKey;
  cin >> answerKey >> k;
  cout << maxConsecutiveAnswers(answerKey, k) << "\n";
  return 0;
}
