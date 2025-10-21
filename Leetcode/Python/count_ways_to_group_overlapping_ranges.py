def main():
  ranges = [list(map(int, input().split())) for _ in range(int(input()))]
  print(countWays(ranges))

def countWays(ranges: list[list[int]]) -> int:
  ranges = sorted(ranges, key=lambda x: x[0])
  buckets = []
  i = 0
  n = len(ranges)
  while i < n:
    mini = ranges[i][0]
    maxi = ranges[i][1]
    j = i + 1
    while j < n and ranges[j][0] <= maxi:
      maxi = max(maxi, ranges[j][1])
      j += 1
    buckets.append([mini, maxi])
    i = j
  return (2**len(buckets)) % (10**9 + 7)

if __name__ == '__main__':
  main()