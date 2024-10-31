def main():
  n = int(input())
  grid = [list(map(int, input().split())) for _ in range(n)]
  print(maxMoves(grid))

def maxMoves(grid: list[list[int]]) -> int:
  rows, cols = len(grid), len(grid[0])
  def func(row, col):
    if (row, col) in memo:
      return memo[(row, col)]
    moves = 0
    for r, c in [(row-1, col+1), (row, col+1), (row+1, col+1)]:
      if 0 <= r < rows and 0 <= c < cols and grid[r][c] > grid[row][col]:
        moves = max(moves, 1 + func(r, c))
    memo[(row, col)] = moves
    return moves
  memo = {}
  max_moves = 0
  for row in range(rows):
    max_moves = max(max_moves, func(row, 0))
  return max_moves

if __name__ == '__main__':
  main()