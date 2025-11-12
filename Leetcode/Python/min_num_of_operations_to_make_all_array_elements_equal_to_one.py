from math import gcd


def main():
  nums = list(map(int, input().split()))
  print(minOperations(nums))

def minOperations(nums: list[int]) -> int:
  n, count_1, total_gcd = len(nums), 0, 0
  for num in nums:
    if num == 1:
      count_1 += 1
    total_gcd = gcd(total_gcd, num)
  
  if total_gcd != 1:
    return -1
  if count_1 > 0:
    return n - count_1

  min_len = n
  for i in range(n):
    total_gcd = 0
    for j in range(i, n):
      total_gcd = gcd(total_gcd, nums[j])
      if total_gcd == 1:
        min_len = min(min_len, j - i + 1)
        break
  
  return min_len - 1 + n - 1

if __name__ == '__main__':
  main()