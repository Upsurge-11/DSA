from collections import deque

class TreeNode(object):
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right

def build_tree(values: list[int]) -> TreeNode:
  if not values:
    return None
  nodes = []
  for val in values:
    if val is None:
      nodes.append(None)
    else:
      nodes.append(TreeNode(val))
  for i in range(len(nodes)):
    left_child_idx = 2 * i + 1
    right_child_idx = 2 * i + 2
    if left_child_idx < len(nodes):
      nodes[i].left = nodes[left_child_idx]
    if right_child_idx < len(nodes):
      nodes[i].right = nodes[right_child_idx]
  return nodes[0]

def main():
  arr = list(map(int, input().split()))
  root = build_tree(arr)
  k = int(input())
  print(kthLargestLevelSum(root, k))

def kthLargestLevelSum(root: TreeNode, k: int) -> int:
  q = deque([root])
  result = []
  while q:
    n = len(q)
    level_sum = 0
    for _ in range(n):
      node = q.popleft()
      level_sum += node.val
      if node.left:
        q.append(node.left)
      if node.right:
        q.append(node.right)
    result.append(level_sum)
  if len(result) < k:
    return -1
  return sorted(result, reverse=True)[k - 1]

if __name__ == '__main__':
  main()