def main():
  nums = [int(x) for x in input().split()]
  maximumBit = int(input())
  print(getMaximumXor(nums, maximumBit))

def getMaximumXor(nums: list[int], maximumBit: int) -> list[int]:
  xor = 0
  for num in nums:
    xor ^= num
  ans = []
  for num in reversed(nums):
    ans.append(xor ^ ((1 << maximumBit) - 1)) # 2**maximumBit - 1
    xor ^= num
  return ans

if __name__ == '__main__':
  main()