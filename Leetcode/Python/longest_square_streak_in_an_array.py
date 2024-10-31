def main():
  arr = list(map(int, input().split()))
  print(longestSquareStreak(arr))

def longestSquareStreak(nums: list[int]) -> int:
  nums.sort()
  ans = -1
  mp = {}
  for num in nums:
    sqrt = num ** 0.5
    if sqrt.is_integer() and sqrt in mp and sqrt * sqrt == num:
      mp[num] = mp[sqrt] + 1
      ans = max(ans, mp[num])
    else:
      mp[num] = 1
  return ans

if __name__ == '__main__':
  main()