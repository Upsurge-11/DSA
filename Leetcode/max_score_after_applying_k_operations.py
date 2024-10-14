import heapq
import math

def main():
  nums = list(map(int, input().split()))
  k = int(input())
  print(maxKelements(nums, k))

def maxKelements(nums: list[int], k: int) -> int:
  heap = []
  ans = 0
  for num in nums:
    heapq.heappush(heap, -num)
  print(heap)
  for _ in range(k):
    max_num = -heapq.heappop(heap)
    print(max_num)
    ans += max_num
    max_num = math.ceil(max_num / 3)
    heapq.heappush(heap, -max_num)
  return ans

if __name__ == '__main__':
  main()