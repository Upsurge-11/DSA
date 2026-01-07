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
  print(maxProduct(root))

def maxProduct(root: TreeNode) -> int:
  def calculate_sum(node: TreeNode) -> int:
    if not node:
      return 0
    return node.val + calculate_sum(node.left) + calculate_sum(node.right)

  total_sum = calculate_sum(root)
  max_product = 0

  def dfs(node: TreeNode) -> int:
    nonlocal max_product
    if not node:
      return 0
    left_sum = dfs(node.left)
    right_sum = dfs(node.right)
    current_sum = node.val + left_sum + right_sum
    product = (total_sum - current_sum) * current_sum
    max_product = max(max_product, product)
    return current_sum

  dfs(root)
  return max_product % (10 ** 9 + 7)

if __name__ == '__main__':
  main()