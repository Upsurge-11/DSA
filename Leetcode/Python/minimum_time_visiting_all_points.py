def main():
  points = [list(map(int, input().split())) for _ in range(int(input()))]
  print(minTimeToVisitAllPoints(points))

def minTimeToVisitAllPoints(points: list[list[int]]) -> int:
  total_time = 0
  for i in range(1, len(points)):
    x1, y1 = points[i - 1]
    x2, y2 = points[i]
    total_time += max(abs(x2 - x1), abs(y2 - y1))
  return total_time

if __name__ == '__main__':
  main()