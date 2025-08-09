def main():
  n = int(input())
  print(isPowerOfTwo(n))

def isPowerOfTwo(n: int) -> bool:
  return n > 0 and (n & (n - 1)) == 0

if __name__ == '__main__':
  main()