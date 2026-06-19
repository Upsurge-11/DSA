def main():
  gain = list(map(int, input().split()))
  print(largestAltitude(gain))

def largestAltitude(gain: list[int]) -> int:
  altitude = 0
  max_altitude = 0

  for g in gain:
    altitude += g
    max_altitude = max(max_altitude, altitude)

  return max_altitude

if __name__ == '__main__':
  main()