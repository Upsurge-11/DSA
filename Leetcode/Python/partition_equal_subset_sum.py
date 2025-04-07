def main():
  nums = [int(x) for x in input().split()]
  print(canPartition(nums))

def canPartition(nums: list[int]) -> bool:
  total = sum(nums)
  if total % 2 != 0:
    return False
  target = total // 2
  dp = [False] * (target + 1)
  dp[0] = True
  for num in nums:
    for currSum in range(target, num - 1, -1):
      dp[currSum] = dp[currSum] or dp[currSum - num]
  return dp[target]

if __name__ == '__main__':
  main()