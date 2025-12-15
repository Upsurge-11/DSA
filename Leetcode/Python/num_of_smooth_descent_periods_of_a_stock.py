def main():
  prices = list(map(int, input().split()))
  print(getDescentPeriods(prices))

def getDescentPeriods(prices: list[int]) -> int:
  ans = 0
  count = 1
  for i in range(len(prices)):
    if i == 0:
      ans += count
      continue
    if prices[i] == prices[i - 1] - 1:
      count += 1
    else:
      count = 1
    ans += count
  return ans

if __name__ == '__main__':
  main()