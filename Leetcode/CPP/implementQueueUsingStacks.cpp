#include <bits/stdc++.h>

using namespace std;

class MyQueue
{
  stack<int> s1, s2;

public:
  MyQueue()
  {
  }

  MyQueue(stack<int> stack1, stack<int> stack2)
  {
    s1 = stack1;
    s2 = stack2;
  }

  void push(int x)
  {
    s1.push(x);
  }

  int pop()
  {
    if (s2.empty())
    {
      while (!s1.empty())
      {
        s2.push(s1.top());
        s1.pop();
      }
    }
    int x = s2.top();
    s2.pop();
    return x;
  }

  int peek()
  {
    if (s2.empty())
    {
      while (!s1.empty())
      {
        s2.push(s1.top());
        s1.pop();
      }
    }
    return s2.top();
  }

  bool empty()
  {
    return s1.empty() && s2.empty();
  }
};

int main()
{

  return 0;
}