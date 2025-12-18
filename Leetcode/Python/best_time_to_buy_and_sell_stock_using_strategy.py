def main():
  prices = list(map(int, input().split()))
  strategy = list(map(int, input().split()))
  k = int(input())
  print(maxProfit(prices, strategy, k))

def maxProfit(prices: list[int], strategy: list[int], k: int)-> int:
  sp = [s * p for s, p in zip(strategy, prices)]
  n = len(prices)
  
  baseline = sum(sp)
  h = k // 2
  old = sum(sp[:k])
  new = sum(prices[h:k])
  maxdiff = max(0, new - old)
  
  for r in range(k, n):
    l = r - k + 1
    old += sp[r] - sp[l - 1]
    new += prices[r]
    new -= prices[l - 1 + h]
    maxdiff = max(maxdiff, new - old)
  
  return baseline + maxdiff

if __name__ == '__main__':
  main()