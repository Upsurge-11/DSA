def main():
  n = int(input())
  batteries = list(map(int, input().split()))
  print(maxRunTime(n, batteries))

def canRun(batteries: list[int], n: int, time: int) -> bool:
  total = 0
  for battery in batteries:
    total += min(battery, time)
    if total >= n * time:
      return True
  return total >= n * time

def maxRunTime(n: int, batteries: list[int]) -> int:
  low , high = 1, 10**14
  while low <= high:
    mid = low + (high - low) // 2
    if canRun(batteries, n, mid):
      low = mid + 1
    else:
      high = mid - 1
  return high

if __name__ == '__main__':
  main()