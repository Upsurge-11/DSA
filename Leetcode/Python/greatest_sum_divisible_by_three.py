def main():
  nums = list(map(int, input().split()))
  print(maxSumDivThree(nums))

dp = {}

def maxSumDivThreeUtility(nums: list[int], sum: int, index: int) -> int:
  if index == len(nums):
    if sum == 0:
      return 0
    else:
      return float('-inf')
  if (index, sum) in dp:
    return dp[(index, sum)]
  pick = nums[index] + maxSumDivThreeUtility(nums, ((sum + nums[index]) % 3), index + 1)
  not_pick = maxSumDivThreeUtility(nums, sum, index + 1)
  dp[(index, sum)] = max(pick, not_pick)
  return dp[(index, sum)]

def maxSumDivThree(nums: list[int]) -> int:
  return maxSumDivThreeUtility(nums, 0, 0)

if __name__ == '__main__':
  main()