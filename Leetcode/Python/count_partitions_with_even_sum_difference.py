def main():
  nums = list(map(int, input().split()))
  print(countPartitions(nums))

def countPartitions(nums: list[int]) -> int:
  return (len(nums) - 1) if sum(nums) % 2 == 0 else 0

if __name__ == '__main__':
  main()