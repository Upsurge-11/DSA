#include <bits/stdc++.h>

using namespace std;

#define ll long long

int countVowelPermutation(int n)
{
  ll a = 1, e = 1, i = 1, o = 1, u = 1, mod = pow(10, 9) + 7;
  ll anext, enext, inext, onext, unext;

  for (int j = 2; j <= n; j++)
  {
    anext = (e + i + u) % mod;
    enext = (a + i) % mod;
    inext = (e + o) % mod;
    onext = (i) % mod;
    unext = (i + o) % mod;

    a = anext, e = enext, i = inext, o = onext, u = unext;
  }
  return (a + e + i + o + u) % mod;
}

int main()
{
  int n;
  cin >> n;
  cout << countVowelPermutation(n) << "\n";
  return 0;
}