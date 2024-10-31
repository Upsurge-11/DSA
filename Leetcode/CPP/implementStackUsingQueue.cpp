#include <bits/stdc++.h>

using namespace std;

class MyStack
{
private:
  queue<int> q1, q2;

public:
  MyStack()
  {
  }

  void push(int x)
  {
    q1.push(x);
  }

  int pop()
  {
    while (q1.size() > 1)
    {
      q2.push(q1.front());
      q1.pop();
    }
    int res = q1.front();
    q1.pop();
    swap(q1, q2);
    return res;
  }

  int top()
  {
    while (q1.size() > 1)
    {
      q2.push(q1.front());
      q1.pop();
    }
    int res = q1.front();
    q2.push(q1.front());
    q1.pop();
    swap(q1, q2);
    return res;
  }

  bool empty()
  {
    if (q1.empty() and q2.empty())
      return true;
    else
      return false;
  }
};

int main()
{

  return 0;
}