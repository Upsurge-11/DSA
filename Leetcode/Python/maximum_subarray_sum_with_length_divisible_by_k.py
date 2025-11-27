def main():
  nums = list(map(int, input().split()))
  k = int(input())
  print(maxSubarraySum(nums, k))

def maxSubarraySum(nums: list[int], k: int) -> int:
  remainder_arr = [float('inf')] * k
  remainder_arr[0] = 0
  res = float('-inf')
  total = 0
  for i, num in enumerate(nums):
    total += num
    length = i + 1
    prefix_remainder = length % k
    res = max(res, total - remainder_arr[prefix_remainder])
    remainder_arr[prefix_remainder] = min(remainder_arr[prefix_remainder], total)
  return res

if __name__ == '__main__':
  main()