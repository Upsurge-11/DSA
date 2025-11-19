def main():
  nums = list(map(int, input().split()))
  original = int(input())
  print(findFinalValue(nums, original))

def findFinalValue(nums: list[int], original: int) -> int:
  num_set = set(nums)
  while original in num_set:
    original *= 2
  return original

if __name__ == '__main__':
  main()