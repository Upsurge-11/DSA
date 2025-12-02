def main():
  points = [list(map(int, input().split())) for _ in range(int(input()))]
  print(countTrapezoids(points))

def countTrapezoids(points: list[list[int]]) -> int:
  MOD = 10**9 + 7
  y_coords_freq = {}
  for _, y in points:
    if y in y_coords_freq:
      y_coords_freq[y] += 1
    else:
      y_coords_freq[y] = 1
  permutation = []
  for freq in y_coords_freq.values():
    if freq >= 2:
      permutation.append(freq * (freq - 1) // 2)
  if len(permutation) < 2:
    return 0
  suffix = [0] * len(permutation)
  suffix[-1] = 0
  for i in range(len(permutation) - 2, -1, -1):
    suffix[i] = suffix[i + 1] + permutation[i + 1]
  result = 0
  for i in range(len(permutation) - 1):
    result = (result + (permutation[i] * suffix[i])) % MOD
  return result

if __name__ == '__main__':
  main()