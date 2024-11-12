def main():
  items = [[int(x) for x in input().split()] for _ in range(int(input()))]
  queries = [int(x) for x in input().split()]
  print(maximumBeauty(items, queries))

def maximumBeauty(items: list[list[int]], queries: list[int]) -> list[int]:
  items.sort()
  queries = sorted([(q, i) for i, q in enumerate(queries)])
  max_beauty = 0
  j = 0
  ans = [0] * len(queries)
  for q, i in queries:
    while j < len(items) and items[j][0] <= q:
      max_beauty = max(max_beauty, items[j][1])
      j += 1
    ans[i] = max_beauty
  return ans

if __name__ == '__main__':
  main()