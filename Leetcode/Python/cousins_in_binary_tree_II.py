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

def bfs(root):
  if not root:
    return []
  result = []
  q = deque([root])
  while q:
    node = q.popleft()
    result.append(node.val)
    if node.left:
      q.append(node.left)
    if node.right:
      q.append(node.right)
  return result

def replaceValueInTree(root: TreeNode) -> TreeNode:
  pq = deque()
  pq.append((root.val, root))
  while pq:
    n = len(pq)
    levelSum = 0
    for localSum, node in pq:
      levelSum += node.val
    for _ in range(n):
      localSum, node = pq.popleft()
      childSum = 0
      if node.left: childSum += node.left.val
      if node.right: childSum += node.right.val
      if node.left: pq.append((childSum, node.left))
      if node.right: pq.append((childSum, node.right))
      node.val = levelSum - localSum
  return root

def main():
  arr = [int(x) if x != 'null' else None for x in input().split()]
  root = build_tree(arr)
  root = replaceValueInTree(root)
  print(bfs(root))

if __name__ == '__main__':
  main()