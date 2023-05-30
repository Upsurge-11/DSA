#include <bits/stdc++.h>

using namespace std;

class MyHashSet
{
  vector<int> hashset;

public:
  MyHashSet()
  {
    hashset.resize(1000001, 0);
  }

  void add(int key)
  {
    hashset[key] = 1;
  }

  void remove(int key)
  {
    hashset[key] = 0;
  }

  bool contains(int key)
  {
    return hashset[key];
  }
};

int main()
{

  return 0;
}