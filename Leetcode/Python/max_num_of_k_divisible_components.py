from collections import defaultdict


def main():
  n = int(input())
  edges = [list(map(int, input().split())) for _ in range(n-1)]
  values = [list(map(int, input().split())) for _ in range(n)]
  k = int(input())
  print(maxKDivisibleComponents(n, edges, values, k))

def maxKDivisibleComponents(n: int, edges: list[list[int]], values: list[int], k: int) -> int:
  adj = defaultdict(list)
  for u, v in edges:
    adj[u].append(v)
    adj[v].append(u)
  
  res = 0
  
  def dfs(curr: int, parent: int) -> int:
    total = values[curr]
    for child in adj[curr]:
      if child != parent:
        total += dfs(child, curr)
    if total % k == 0:
      nonlocal res
      res += 1
    return total
  
  dfs(0, -1)
  return res

if __name__ == '__main__':
  main()