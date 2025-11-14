def main():
  n = int(input())
  queries = [list(map(int, input().split())) for _ in range(int(input()))]
  print(rangeAddQueries(n, queries))

# def rangeAddQueries(n: int, queries: list[list[int]]) -> list[list[int]]:
#   matrix = [[0] * n for _ in range(n)]
#   for r1, c1, r2, c2 in queries:
#     for i in range(r1, r2 + 1):
#       for j in range(c1, c2 + 1):
#         matrix[i][j] += 1
#   return matrix

def rangeAddQueries(n: int, queries: list[list[int]]) -> list[list[int]]:
  diff_matrix = [[0] * (n + 1) for _ in range(n + 1)]
  for r1, c1, r2, c2 in queries:
    diff_matrix[r1][c1] += 1
    diff_matrix[r1][c2 + 1] -= 1
    diff_matrix[r2 + 1][c1] -= 1
    diff_matrix[r2 + 1][c2 + 1] += 1
  
  res = [[0] * n for _ in range(n)]
  
  for r in range(n):
    for c in range(n):
      top = 0 if r == 0 else res[r - 1][c]
      left = 0 if c == 0 else res[r][c - 1]
      top_left = 0 if r == 0 or c == 0 else res[r - 1][c - 1]
      res[r][c] = diff_matrix[r][c] + top + left - top_left
  return res

if __name__ == '__main__':
  main()