def main():
  nums = list(map(int, input().split()))
  queries = [list(map(int, input().split())) for _ in range(int(input()))]
  print(xorAfterQueries(nums, queries))

def xorAfterQueries(nums: list[int], queries: list[list[int]]) -> int:
  for l, r, k, v in queries:
    for i in range(l, r+1, k):
      nums[i] = (nums[i] * v) % 1000000007
  res = 0
  for num in nums:
    res ^= num
  return res

if __name__ == '__main__':
  main()