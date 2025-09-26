def main():
  nums = list(map(int, input().split()))
  print(triangleNumber(nums))

def triangleNumber(nums: list[int]) -> int:
  nums.sort()
  count = 0
  for i in range(len(nums) - 1, 1, -1):
    left, right = 0, i - 1
    while left < right:
      if nums[left] + nums[right] > nums[i]:
        count += right - left
        right -= 1
      else:
        left += 1
  return count

if __name__ == '__main__':
  main()