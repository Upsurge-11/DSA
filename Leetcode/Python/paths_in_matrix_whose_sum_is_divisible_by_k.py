def main():
  grid = [list(map(int, input().split())) for _ in range(int(input()))]
  k = int(input())
  print(numberOfPaths(grid, k))

memo = {}

def countPaths(grid: list[list[int]], k: int, row: int, col: int, current_sum: int) -> int:
  MOD = 10**9 + 7
  if row >= len(grid) or col >= len(grid[0]):
    return 0
  current_sum += (grid[row][col]) % k
  if row == len(grid) - 1 and col == len(grid[0]) - 1:
    return 1 if current_sum % k == 0 else 0
  if (row, col, current_sum) in memo:
    return memo[(row, col, current_sum)]
  go_down = countPaths(grid, k, row + 1, col, current_sum)
  go_right = countPaths(grid, k, row, col + 1, current_sum)
  memo[(row, col, current_sum)] = (go_down + go_right) % MOD
  return memo[(row, col, current_sum)]

def numberOfPaths(grid: list[list[int]], k: int) -> int:
  return countPaths(grid, k, 0, 0, 0)

if __name__ == '__main__':
  main()