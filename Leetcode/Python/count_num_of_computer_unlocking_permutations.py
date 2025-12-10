def main():
  complexity = list(map(int, input().split()))
  print(countPermutations(complexity))

def countPermutations(complexity: list[int]) -> int:
  MOD = 10**9 + 7
  min_complexity = min(complexity)
  count_min = complexity.count(min_complexity)
  if count_min > 1 or complexity[0] != min_complexity:
    return 0
  dp = [0] * (len(complexity) + 1)
  dp[0] = dp[1] = 1
  def factorial(n: int) -> int:
    if n == 0 or n == 1:
      return dp[n]
    if dp[n] != 0:
      return dp[n]
    dp[n] = (n * factorial(n - 1)) % MOD
    return dp[n]
  return factorial(len(complexity)-1)

if __name__ == '__main__':
  main()