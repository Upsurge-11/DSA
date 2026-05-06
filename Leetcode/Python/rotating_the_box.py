def main():
  boxGrid = [list(map(str, input().split())) for _ in range(int(input()))]
  print(rotateTheBox(boxGrid))

def rotateTheBox(boxGrid: list[list[str]]) -> list[list[str]]:
  rows, cols = len(boxGrid), len(boxGrid[0])
  for r in range(rows):
    p = 0
    for c in range(cols):
      if boxGrid[r][c] == '.':
        boxGrid[r][c], boxGrid[r][p] = boxGrid[r][p], boxGrid[r][c]
        p += 1
      elif boxGrid[r][c] == '*':
        p = c + 1
  rotatedBox = [[0] * rows for _ in range(cols)]
  for r in range(rows):
    for c in range(cols):
      rotatedBox[c][rows - 1 - r] = boxGrid[r][c]
  return rotatedBox

if __name__ == '__main__':
  main()