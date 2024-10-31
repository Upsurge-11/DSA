def main():
  arr = list(map(int, input().split()))
  print(minimumMountainRemovals(arr))

def minimumMountainRemovals(nums: list[int]) -> int:
  n = len(nums)
  LIS = [1] * n
  LDS = [1] * n
  
  for i in range(n):
    for j in range(i):
      if nums[i] > nums[j]:
        LIS[i] = max(LIS[i], LIS[j] + 1)
  
  for i in range(n - 1, -1, -1):
    for j in range(n - 1, i, -1):
      if nums[i] > nums[j]:
        LDS[i] = max(LDS[i], LDS[j] + 1)
  
  ans = 0
  for i in range(1, n-1):
    if LIS[i] > 1 and LDS[i] > 1:
      ans = max(ans, LIS[i] + LDS[i] - 1)
  return n - ans

if __name__ == '__main__':
  main()