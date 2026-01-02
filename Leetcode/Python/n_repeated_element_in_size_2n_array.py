from collections import Counter

def main():
  nums = list(map(int, input().split()))
  print(repeatedNTimes(nums))

def repeatedNTimes(nums: list[int]) -> int:
  n = len(set(nums)) - 1
  count = Counter(nums)
  for num, freq in count.items():
    if freq == n:
      return num
  return -1

if __name__ == '__main__':
  main()