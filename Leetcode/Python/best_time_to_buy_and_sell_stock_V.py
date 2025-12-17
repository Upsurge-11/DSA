def main():
  prices = list(map(int, input().split()))
  k = int(input())
  print(maximumProfit(prices, k))

def maximumProfit(prices: list[int], k: int) -> int:
  n = len(prices)
  if k == 0: return 0
  dp = [[[-float('inf') for _ in range(k+1)] for _ in range(3)] for _ in range(n)]
  dp[0][0][0] = 0
  dp[0][1][0] = -prices[0]
  dp[0][2][0] = prices[0]
  
  for i in range(1, n):
    for count in range(k+1):
      dp[i][0][count] = dp[i-1][0][count]

      if count > 0:
        dp[i][0][count] = max(
          dp[i][0][count],
          dp[i-1][1][count-1] + prices[i],
          dp[i-1][2][count-1] - prices[i]
        )

      dp[i][1][count] = max(
        dp[i-1][1][count],
        dp[i-1][0][count] - prices[i]
      )

      dp[i][2][count] = max(
        dp[i-1][2][count],
        dp[i-1][0][count] + prices[i]
      )

  return max(dp[n-1][0][i] for i in range(1,k+1))

if __name__ == '__main__':
  main()