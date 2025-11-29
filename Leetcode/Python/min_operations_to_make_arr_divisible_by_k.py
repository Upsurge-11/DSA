def main():
  nums = list(map(int, input().split()))
  k = int(input())
  print(minOperations(nums, k))

def minOperations(nums: list[int], k: int) -> int:
  return sum(nums)%k

if __name__ == '__main__':
  main()