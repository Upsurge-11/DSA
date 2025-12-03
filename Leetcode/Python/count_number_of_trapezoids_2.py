from collections import defaultdict

def main():
  points = [list(map(int, input().split())) for _ in range(int(input()))]
  print(countTrapezoids(points))

def countTrapezoids(points: list[list[int]]) -> int:
  seen_points = []
  parallel_count = defaultdict(int)
  same_line_count = defaultdict(int)
  parallel_side_count = defaultdict(int)
  same_line_side_count = defaultdict(int)
  
  result = 0
  rhombus_count = 0
  
  for x1, y1 in points:
    for x2, y2 in seen_points:
      dx = x1 - x2
      dy = y1 - y2
      if dx == 0:
        slope = 'inf'
        intercept = x1
      else:
        slope = dy / dx
        intercept = y1 - slope * x1
        slope = round(slope, 8)
        intercept = round(intercept, 8)
      line = (slope, intercept)
      result += parallel_count[slope] - same_line_count[line]
      parallel_count[slope] += 1
      same_line_count[line] += 1
      
      side_len = dx * dx + dy * dy
      rhombus_count += parallel_side_count[(slope, side_len)] - same_line_side_count[(line, side_len)]
      parallel_side_count[(slope, side_len)] += 1
      same_line_side_count[(line, side_len)] += 1
    seen_points.append((x1, y1))
  return result - rhombus_count // 2

if __name__ == '__main__':
  main()