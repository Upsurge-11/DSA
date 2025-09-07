def main():
  n = int(input())
  print(sumZero(n))

def sumZero(n : int) -> list[int]:
  if n % 2 == 1:
    return [i for i in range(-(n // 2), n // 2 + 1)]
  else:
    return [i for i in range(-n // 2, 0)] + [i for i in range(1, n // 2 + 1)]

if __name__ == '__main__':
  main()