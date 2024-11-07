def main():
  nums = [int(x) for x in input().split()]
  print(largestCombination(nums))

def largestCombination(nums: list[int]) -> int:
  ans = 0
  for i in range(32):
    count = 0
    for num in nums:
      if num & (1 << i):
        count += 1
    ans = max(ans, count)
  return ans

if __name__ == '__main__':
  main()