def main():
  nums = list(map(int, input().split()))
  print(minBitwiseArray(nums))

def minBitwiseArray(nums: list[int]) -> list[int]:
  res = []
  for n in nums:
    if n & 1:
      res.append(n & ~(((n + 1) & ~n) >> 1))
    else:
      res.append(-1)
  return res

if __name__ == '__main__':
  main()