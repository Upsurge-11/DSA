def main():
  n = int(input())
  print(numOfWays(n))

def numOfWays(n: int) -> int:
  MOD = 10**9 + 7
  dp = [[[[-1 for _ in range(4)] for _ in range(4)] for _ in range(4)] for _ in range(n)]
  def helper(index: int, prev1 : int, prev2 : int, prev3 : int) -> int:
    if index == n:
      return 1
    if dp[index][prev1][prev2][prev3] != -1:
      return dp[index][prev1][prev2][prev3]
    total = 0
    for col1 in range(1, 4):
      if col1 == prev1:
        continue
      for col2 in range(1, 4):
        if col2 == prev2 or col2 == col1:
          continue
        for col3 in range(1, 4):
          if col3 == prev3 or col3 == col2:
            continue
          total = (total + helper(index + 1, col1, col2, col3)) % MOD
    dp[index][prev1][prev2][prev3] = total
    return total
  return helper(0, 0, 0, 0)

if __name__ == '__main__':
  main()