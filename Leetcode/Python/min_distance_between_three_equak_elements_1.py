from itertools import combinations


def main():
  nums = list(map(int, input().split()))
  print(minimumDistance(nums))

def minimumDistance(nums: list[int]) -> int:
  freq = {}
  for i in range(len(nums)):
    if nums[i] not in freq:
      freq[nums[i]] = []
    freq[nums[i]].append(i)

  min_dist = float('inf')
  
  for key, indices in freq.items():
    if len(indices) >= 3:
      for combo in combinations(indices, 3):
        a, b, c = combo
        dist = abs(a - b) + abs(b - c) + abs(c - a)
        min_dist = min(min_dist, dist)
  
  return min_dist if min_dist != float('inf') else -1

if __name__ == '__main__':
  main()