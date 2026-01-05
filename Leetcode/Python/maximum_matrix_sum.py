def main():
  n = int(input())
  matrix = [list(map(int, input().split())) for _ in range(n)]
  print(maxMatrixSum(matrix))

def maxMatrixSum(matrix: list[list[int]]) -> int:
  total_sum = 0
  negative_count = 0
  min_abs_value = float('inf')

  for row in matrix:
    for value in row:
      abs_value = abs(value)
      total_sum += abs_value
      if value < 0:
        negative_count += 1
      min_abs_value = min(min_abs_value, abs_value)

  if negative_count % 2 == 0:
    return total_sum
  else:
    return total_sum - 2 * min_abs_value

if __name__ == '__main__':
  main()