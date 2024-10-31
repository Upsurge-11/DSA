# def maxWidthRamp(nums: list[int]) -> int:
#   ans = 0
#   for i in range(len(nums) - 1):
#     for j in range(i + 1, len(nums)):
#       if nums[j] >= nums[i]:
#         ans = max(ans, j - i)
#   return ans

def maxWidthRamp(nums: list[int]) -> int:
  n = len(nums)
  stack = []
  for i in range(n):
    if not stack or nums[stack[-1]] > nums[i]:
      stack.append(i)
  ans = 0
  for i in range(n - 1, 0, -1):
    while stack and nums[stack[-1]] <= nums[i]:
      ans = max(ans, i - stack.pop())
  return ans


def main():
  nums = list(map(int, input().split()))
  print(maxWidthRamp(nums))

if __name__ == '__main__':
  main()