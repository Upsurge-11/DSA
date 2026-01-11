def main():
  matrix = [list(map(str, input().split())) for _ in range(int(input()))]
  print(maximalRectangle(matrix))

def maximalRectangle(matrix: list[list[str]]) -> int:
  if not matrix or not matrix[0]:
    return 0
  m = len(matrix)
  n = len(matrix[0])
  
  for i in range(m):
    for j in range(n):
      matrix[i][j] = int(matrix[i][j])
  
  for i in range(m):
    for j in range(1, n):
      if matrix[i][j] == 1:
        matrix[i][j] += matrix[i][j - 1]
  
  max_area = 0
  
  for j in range(n):
    for i in range(m):
      width = matrix[i][j]
      if width == 0:
        continue
      currWidth = width
      k = i
      while k < m and matrix[k][j] > 0:
        currWidth = min(currWidth, matrix[k][j])
        height = k - i + 1
        max_area = max(max_area, currWidth * height)
        k += 1
      
      currWidth = width
      k = i
      while k >= 0 and matrix[k][j] > 0:
        currWidth = min(currWidth, matrix[k][j])
        height = i - k + 1
        max_area = max(max_area, currWidth * height)
        k -= 1
  return max_area

if __name__ == '__main__':
  main()