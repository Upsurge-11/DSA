def main():
  s = input()
  print(minimumSteps(s))

def minimumSteps(s: str) -> int:
  ans, white = 0, 0
  for i in range(len(s)):
    if s[i] == '0':
      ans += white
    elif s[i] == '1':
      white += 1
  return ans

if __name__ == '__main__':
  main()