#include <bits/stdc++.h>

using namespace std;

double average(vector<int> &salary)
{
  double sum = 0;
  sort(salary.begin(), salary.end());
  for (int i = 1; i < salary.size() - 1; i++)
    sum += salary[i];
  return sum / (salary.size() - 2);
}

int main()
{
  int n;
  cin >> n;
  vector<int> salary(n);
  for (int i = 0; i < n; i++)
    cin >> salary[i];
  cout << average(salary) << "\n";

  return 0;
}