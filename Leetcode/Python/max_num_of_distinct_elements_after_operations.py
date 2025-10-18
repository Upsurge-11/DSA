import math

def main():
  nums = list(map(int, input().split()))
  k = int(input())
  print(maxDistinctElements(nums, k))

def maxDistinctElements(nums: list[int], k: int) -> int:
  if len(nums) <= ((k*2) + 1):
    return len(nums)
  nums = sorted(nums)
  current = -math.inf
  res = 0
  for num in nums:
    target = max(current + 1, num - k)
    if target <= num + k:
      res += 1
      current = target
    else:
      current = max(current, num)
  return res

if __name__ == '__main__':
  main()