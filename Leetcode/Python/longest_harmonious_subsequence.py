import collections

def main():
  nums = list(map(int, input().split()))
  return findLHS(nums)

def findLHS(nums : list[int]) -> int:
  f = collections.Counter(nums)
  ans = 0
  for k in f.keys():
    if f[k] > 0 and f[k + 1] > 0:
      ans = max(ans, f[k] + f[k + 1])
  return ans

if __name__ == '__main__':
  main()