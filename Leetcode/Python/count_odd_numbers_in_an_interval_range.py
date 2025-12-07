def main():
  low, high = map(int, input().split())
  print(countOdds(low, high))

def countOdds(low: int, high: int) -> int:
  return (high + 1) // 2 - (low // 2)

if __name__ == '__main__':
  main()