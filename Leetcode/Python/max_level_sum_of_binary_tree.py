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
  root = build_tree(list(map(int, input().split())))
  print(maxLevelSum(root))

def maxLevelSum(root: TreeNode) -> int:
  def dfs(root):
    if not root:
      return []
    max_sum = float('-inf')
    max_level = level = 0
    q = []
    q.append(root)
    while q:
      size = len(q)
      sum = 0
      level += 1
      for _ in range(size):
        node = q.pop(0)
        sum += node.val
        if node.left:
          q.append(node.left)
        if node.right:
          q.append(node.right)
      if sum > max_sum:
        max_sum = sum
        max_level = level
    return max_level
  return dfs(root)

if __name__ == '__main__':
  main()