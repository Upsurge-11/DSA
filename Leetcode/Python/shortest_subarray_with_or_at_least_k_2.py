def main():
  nums = [int(x) for x in input().split()]
  k = int(input())
  print(minimumSubarrayLength(nums, k))

def minimumSubarrayLength(nums: list[int], k: int) -> int:
  res = float('inf')
  l = 0
  bits = [0] * 32
  for r in range(len(nums)):
    for i in range(32):
      if nums[r] & (1 << i):
        bits[i] += 1
    curr_or_value = 0
    for i in range(32):
      if bits[i]:
        curr_or_value += (1 << i)
    while l <= r and curr_or_value >= k:
      res = min(res, r-l+1)
      for i in range(32):
        if nums[l] & (1 << i):
          bits[i] -= 1
      curr_or_value = 0
      for i in range(32):
        if bits[i]:
          curr_or_value += (1 << i)
      l += 1
  return -1 if res == float('inf') else res

if __name__ == '__main__':
  main()