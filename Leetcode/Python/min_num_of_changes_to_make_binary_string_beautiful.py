def main():
  s = input()
  print(minChanges(s))

def minChanges(s: str) -> int:
  ans = 0
  for i in range(1, len(s), 2):
    if s[i] != s[i - 1]:
      ans += 1
  return ans

if __name__ == '__main__':
  main()