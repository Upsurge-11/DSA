from collections import Counter

def main():
  n = int(input())
  print(reorderedPowerOf2(n))

def reorderedPowerOf2(n: int) -> bool:
  count = Counter(str(n))
  for i in range(31):
    if count == Counter(str(1 << i)):
      return True
  return False

if __name__ == '__main__':
  main()