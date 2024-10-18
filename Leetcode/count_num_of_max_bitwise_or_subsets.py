def main():
  nums = list(map(int, input().split()))
  print(countMaxOrSubsets(nums))

def countMaxOrSubsets(nums: list[int]) -> int:
  max_or_value = 0
  for num in nums:
    max_or_value |= num
  return countMaxOrValueSubsets(0, 0 ,max_or_value, 0, nums)

def countMaxOrValueSubsets(ans: int, curr_or_value: int, max_or_value: int, index: int, nums: list[int]) -> int:
  if index == len(nums):
    if curr_or_value == max_or_value:
      ans += 1
    return ans
  ans = countMaxOrValueSubsets(ans, curr_or_value | nums[index], max_or_value, index + 1, nums) + countMaxOrValueSubsets(ans, curr_or_value, max_or_value, index + 1, nums)
  return ans

if __name__ == '__main__':
  main()