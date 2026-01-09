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
  root_array = list(map(int, input().split()))
  root = build_tree(root_array)
  print(subtreeWithAllDeepest(root))

def subtreeWithAllDeepest(root: TreeNode) -> TreeNode:
  lca = None
  max_depth = 0
  def dfs(root: TreeNode, depth: int) -> int:
    nonlocal max_depth
    max_depth = max(max_depth, depth)
    if not root:
      return depth
    left = dfs(root.left, depth + 1)
    right = dfs(root.right, depth + 1)
    if left == right == max_depth:
      nonlocal lca
      lca = root
    return max(left, right)
  dfs(root, 0)
  return lca

if __name__ == '__main__':
  main()