def main():
  grid = [list(map(int, input().split())) for _ in range(int(input()))]
  print(getBiggestThree(grid))

def getBiggestThree(grid: list[list[int]]) -> list[int]:
  m, n = len(grid), len(grid[0])
  sums = set()
  for i in range(m):
    for j in range(n):
      sums.add(grid[i][j])
      for k in range(1, min(i, j, m - 1 - i, n - 1 - j) + 1):
        s = grid[i - k][j] + grid[i + k][j] + grid[i][j - k] + grid[i][j + k]
        for l in range(1, k):
          s += grid[i - l][j - (k - l)] + grid[i - l][j + (k - l)] + grid[i + l][j - (k - l)] + grid[i + l][j + (k - l)]
        sums.add(s)
  return sorted(sums, reverse=True)[:3]

if __name__ == '__main__':
  main()