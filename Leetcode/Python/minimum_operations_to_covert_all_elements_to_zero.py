def main():
  nums = list(map(int, input().split()))
  print(minOperations(nums))

def minOperations(nums: list[int]) -> int:
  stack = []
  res = 0
  for n in nums:
    while stack and stack[-1] > n:
      stack.pop()
    if n == 0:
      continue
    if not stack or stack[-1] < n:
      res += 1
      stack.append(n)
  return res

if __name__ == '__main__':
  main()