#include <bits/stdc++.h>
#include <sys/types.h>

using namespace std;

// 2719. Count of Integers

const long long MOD = 1e9 + 7;
long long dp[23][2][2][401];

long long countStrings(long long ind, bool tight1, bool tight2, long long sum,
                       string &num1, string &num2) {
  if (sum < 0)
    return 0;
  if (ind == num2.size())
    return 1;
  if (dp[ind][tight1][tight2][sum] != -1)
    return dp[ind][tight1][tight2][sum];
  long long lo = (tight1) ? num1[ind] - '0' : 0;
  long long hi = (tight2) ? num2[ind] - '0' : 9;
  long long count = 0;
  for (long long i = lo; i <= hi; i++) {
    count =
        (count % MOD + countStrings(ind + 1, tight1 & (i == lo),
                                    tight2 & (i == hi), sum - i, num1, num2) %
                           MOD) %
        MOD;
  }
  return dp[ind][tight1][tight2][sum] = count;
}

int count(string num1, string num2, int min_sum, int max_sum) {
  memset(dp, -1, sizeof(dp));
  string num1extended = "";
  long long n1 = num1.size();
  long long n2 = num2.size();
  long long d = n2 - n1;
  for (int i = 0; i < d; i++) {
    num1extended += "0";
  }
  num1extended += num1;
  long long a = countStrings(0, 1, 1, max_sum, num1extended, num2);
  memset(dp, -1, sizeof(dp));
  long long b = countStrings(0, 1, 1, min_sum - 1, num1extended, num2);
  long long ans = (a - b) % MOD;
  return (ans < 0) ? ans + MOD : ans;
}

int main() {
  string num1, num2;
  cin >> num1 >> num2;
  int min_sum, max_sum;
  cin >> min_sum >> max_sum;
  cout << count(num1, num2, min_sum, max_sum) << "\n";
  return 0;
}
