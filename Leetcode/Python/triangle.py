memo = {}

def main():
  triangle = [list(map(int, input().split())) for _ in range(int(input()))]
  print(minimumTotal(triangle))

def func(triangle, i, j):
  if (i, j) in memo:
    return memo[(i, j)]
  if i == len(triangle) - 1:
    return triangle[i][j]
  current_value = triangle[i][j]
  left = func(triangle, i + 1, j)
  right = func(triangle, i + 1, j + 1)
  memo[(i, j)] = current_value + min(left, right)
  return memo[(i, j)]

def minimumTotal(triangle: list[list[int]]) -> int:
  memo.clear()
  return func(triangle, 0, 0)

if __name__ == '__main__':
  main()