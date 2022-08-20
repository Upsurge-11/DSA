#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
  int data;
  Node *next;
};

void printList(Node *n)
{
  while (n != NULL)
  {
    cout << n->data << " ";
    n = n->next;
  }
  cout << "\n";
}

Node *reverseLinkedList(Node *head)
{
  Node *newHead = NULL;
  while (head != NULL)
  {
    Node *next = head->next;
    head->next = newHead;
    newHead = head;
    head = next;
  }
  return newHead;
}

int main()
{
  int n;
  cin >> n;
  int x;
  cin >> x;
  Node *head = new Node();
  head->data = x;
  Node *temp = head;

  for (int i = 0; i < n - 1; i++)
  {
    cin >> x;
    temp->next = new Node();
    temp->next->data = x;
    temp = temp->next;
  }

  printList(head);

  reverseLinkedList(head);

  printList(temp);

  return 0;
}