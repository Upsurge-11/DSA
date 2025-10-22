from collections import Counter
from bisect import bisect_left, bisect_right

def main():
  nums = list(map(int, input().split()))
  k = int(input())
  numOperations = int(input())
  print(maxFrequency(nums, k, numOperations))

def maxFrequency(nums: list[int], k: int, numOperations: int) -> int:
  if not nums:
    return 0
  nums.sort()
  n = len(nums)
  freq = Counter(nums)
  ans = 1
  
  for v, already in freq.items():
    lowVal = v - k
    highVal = v + k
    L = bisect_left(nums, lowVal)
    R = bisect_right(nums, highVal)
    total_in_range = R - L
    need = total_in_range - already
    can_fix = min(need, numOperations)
    ans = max(ans, already + can_fix)
  
  l = 0
  for r in range(n):
    while l <= r and nums[r] - nums[l] > 2*k:
      l += 1
    w = r - l + 1
    ans = max(ans, min(w, numOperations))
  
  return ans

if __name__ == '__main__':
  main()