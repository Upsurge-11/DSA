def main():
  nums = list(map(int, input().split()))
  print(minimumOperations(nums))

def minimumOperations(nums : list[int]) -> int:
  ans = 0
  while len(nums) != len(set(nums)):
    nums = nums[3:]
    ans += 1
  return ans

if __name__ == '__main__':
  main()