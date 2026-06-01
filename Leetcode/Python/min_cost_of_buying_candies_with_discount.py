def main():
  cost = list(map(int, input().split()))
  print(minimumCost(cost))

def minimumCost(cost: list[int]) -> int:
  cost.sort(reverse=True)
  total = 0
  for i in range(len(cost)):
    if i % 3 != 2:
      total += cost[i]
  return total

if __name__ == '__main__':
  main()