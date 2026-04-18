def main():
  n = int(input())
  print(mirrorDistance(n))

def mirrorDistance(n: int) -> int:
  return abs(n - int(str(n)[::-1]))

if __name__ == '__main__':
  main()