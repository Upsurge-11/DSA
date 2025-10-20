def main():
  operations = list(map(str, input().split()))
  print(finalValueAfterOperations(operations))

def finalValueAfterOperations(operations: list[str]) -> int:
  x = 0
  for operation in operations:
    if operation in ("++X", "X++"):
      x += 1
    else:
      x -= 1
  return x

if __name__ == '__main__':
  main()