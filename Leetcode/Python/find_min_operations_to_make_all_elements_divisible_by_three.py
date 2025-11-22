def main():
  nums = list(map(int, input().split()))
  print(minimumOperations(nums))

def minimumOperations(nums: list[int]) -> int:
  res = 0
  for num in nums:
    if num % 3 == 0:
      res += 0
    else:
      res += min(3 - (num % 3), num % 3)
  return res

if __name__ == '__main__':
  main()