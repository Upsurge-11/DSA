def main():
  n = int(input())
  buildings = [list(map(int, input().split())) for _ in range(2)]
  print(countCoveredBuildings(n, buildings))

def countCoveredBuildings(n: int, buildings: list[list[int]]) -> int:
  rmax = [0] * (n+1)
  rmin = [n+1] * (n+1)
  cmax = [0] * (n+1)
  cmin = [n+1] * (n+1)

  for x, y in buildings:
    rmax[y] = max(rmax[y], x)
    rmin[y] = min(rmin[y], x)
    cmax[x] = max(cmax[x], y)
    cmin[x] = min(cmin[x], y)

  count = 0
  for x, y in buildings:
    if rmin[y] < x < rmax[y] and cmin[x] < y < cmax[x]:
      count += 1

  return count

if __name__ == '__main__':
  main()