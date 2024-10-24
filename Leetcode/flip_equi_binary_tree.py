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
  arr = [int(x) if x != 'null' else None for x in input().split()]
  root1 = build_tree(arr)
  arr = [int(x) if x != 'null' else None for x in input().split()]
  root2 = build_tree(arr)
  print(flipEquiv(root1, root2))

def flipEquiv(root1: TreeNode, root2: TreeNode) -> bool:
  def checker(node1, node2):
    if not node1 and not node2:
      return True
    if not node1 or not node2 or node1.val != node2.val:
      return False
    return ((checker(node1.left, node2.left) or checker(node1.left, node2.right)) and (checker(node1.right, node2.right) or checker(node1.right, node2.left)))
  return checker(root1, root2)

if __name__ == '__main__':
  main()