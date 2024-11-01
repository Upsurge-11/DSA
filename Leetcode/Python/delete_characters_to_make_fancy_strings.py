def main():
  s = input()
  print(makeFancyString(s))

def makeFancyString(s: str) -> str:
  ans = ''
  for i in range(len(s)):
    if i <= 1 or not(s[i] == s[i - 1] == s[i - 2]):
      ans += s[i]
  return ans

if __name__ == '__main__':
  main()