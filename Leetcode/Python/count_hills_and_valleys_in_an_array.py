def main():
  nums = list(map(int, input().split()))
  print(countHillValley(nums))

def countHillValley(nums: list[int]) -> int:
  count = 0
  left = 0
  for i in range(1, len(nums) - 1):
    if (nums[left] < nums[i] > nums[i + 1]) or (nums[left] > nums[i] < nums[i + 1]):
      count += 1
      left = i
  return count

if __name__ == '__main__':
  main()