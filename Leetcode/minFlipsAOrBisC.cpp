#include <bits/stdc++.h>

using namespace std;

string decimalToBinary(int n) {
  string s = bitset<64>(n).to_string();
  const auto loc1 = s.find('1');
  if (loc1 != string::npos)
    return s.substr(loc1);
  return "0";
}

int minFlips(int a, int b, int c) {
  string aBin = decimalToBinary(a);
  string bBin = decimalToBinary(b);
  string cBin = decimalToBinary(c);
  int maxLen = max(aBin.length(), max(bBin.length(), cBin.length()));
  while (aBin.length() < maxLen)
    aBin = "0" + aBin;
  while (bBin.length() < maxLen)
    bBin = "0" + bBin;
  while (cBin.length() < maxLen)
    cBin = "0" + cBin;
  int ans = 0;
  for (int i = 0; i < maxLen; i++) {
    if (cBin[i] == '0') {
      if (aBin[i] == '1')
        ans++;
      if (bBin[i] == '1')
        ans++;
    } else {
      if (aBin[i] == '0' && bBin[i] == '0')
        ans++;
    }
  }
  return ans;
}

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  cout << minFlips(a, b, c) << "\n";
  return 0;
}
