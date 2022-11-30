#include <bits/stdc++.h>

using namespace std;

class RandomizedSet
{
  unordered_map<int, int> m;
  vector<int> v;
  int size;

public:
  RandomizedSet()
  {
    size = 0;
  }

  bool insert(int val)
  {
    if (m.find(val) != m.end())
      return false;
    m[val] = size;
    v.push_back(val);
    size++;
    return true;
  }

  bool remove(int val)
  {
    if (m.find(val) == m.end())
      return false;
    int index = m[val];
    m[v[size - 1]] = index;
    v[index] = v[size - 1];
    v.pop_back();
    m.erase(val);
    size--;
    return true;
  }

  int getRandom()
  {
    return v[rand() % size];
  }
};

int main()
{

  return 0;
}