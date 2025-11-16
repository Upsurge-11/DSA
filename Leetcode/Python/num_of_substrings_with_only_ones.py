def main():
  s = input().strip()
  print(numSub(s))

def numSub(s: str) -> int:
  MOD = 10**9 + 7
  count = 0
  result = 0

  for char in s:
    if char == '1':
      count += 1
    else:
      count = 0
    result = (result + count) % MOD
  return result

if __name__ == '__main__':
  main()