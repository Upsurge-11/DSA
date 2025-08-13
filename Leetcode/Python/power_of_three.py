def main():
  n = int(input())
  print(isPowerOfThree(n))

def isPowerOfThree(n: int) -> bool:
  if n <= 0:
    return False
  while n % 3 == 0:
    n //= 3
  return n == 1

if __name__ == '__main__':
  main()