def main():
  low, high, zero, one = [int(x) for x in input().split()]
  print(countGoodStrings(low, high, zero, one))

def countGoodStrings(low: int, high: int, zero: int, one: int) -> int:
  dp = {}
  mod = 10**9 + 7
  def func(length: int) -> int:
    if length > high:
      return 0
    if length in dp:
      return dp[length]
    if length >= low:
      dp[length] = 1 
    else: dp[length] = 0
    dp[length] += func(length + zero) + func(length + one)
    return dp[length] % mod
  return func(0)

if __name__ == '__main__':
  main()