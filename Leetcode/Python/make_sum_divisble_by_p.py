def main():
  nums = list(map(int, input().split()))
  p = int(input())
  print(minSubarray(nums, p))

def minSubarray(nums: list[int], p: int) -> int:
  remainder = sum(nums) % p
  if remainder == 0:
    return 0
  res = len(nums)
  curr_sum = 0
  remainder_at_index = {0: -1}
  
  for i, n in enumerate(nums):
    curr_sum = (curr_sum + n) % p
    prefix = (curr_sum - remainder + p) % p
    if prefix in remainder_at_index:
      res = min(res, i - remainder_at_index[prefix])
    remainder_at_index[curr_sum] = i
  
  return -1 if res == len(nums) else res

if __name__ == '__main__':
  main()