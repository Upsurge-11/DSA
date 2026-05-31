def main():
  mass = int(input())
  asteroids = list(map(int, input().split()))
  print(asteroidsDestroyed(mass, asteroids))

def asteroidsDestroyed(mass: int, asteroids: list[int]) -> bool:
  asteroids.sort()
  for asteroid in asteroids:
    if mass < asteroid:
      return False
    mass += asteroid
  return True

if __name__ == '__main__':
  main()