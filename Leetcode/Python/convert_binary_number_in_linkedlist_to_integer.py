class ListNode:
  def __init__(self, value=0, next=None):
    self.value = value
    self.next = next

def build_linked_list_from_list(values : list[int]) -> ListNode:
  if not values:
    return None
  head = ListNode(values[0])
  current = head
  for val in values[1:]:
    current.next = ListNode(val)
    current = current.next
  return head

def print_linked_list(head: ListNode) -> None:
  current = head
  values = []
  while current:
    values.append(str(current.value))
    current = current.next
  print(" -> ".join(values))

def main():
  arr = list(map(int, input().split()))
  head = build_linked_list_from_list(arr)
  print_linked_list(head)
  print(getDecimalValue(head))

def getDecimalValue(head: ListNode) -> int:
  current = head
  result = 0
  while current:
    result = (result << 1) | current.value
    current = current.next
  return result

if __name__ == '__main__':
  main()