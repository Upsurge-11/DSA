def minSwaps(s: str) -> int:
  ans = 0
  for c in s:
    if c == '[':
      ans += 1
    elif ans > 0:
      ans -= 1
  return (ans + 1) // 2

def main():
  s = input()
  print(minSwaps(s))

if __name__ == '__main__':
  main()