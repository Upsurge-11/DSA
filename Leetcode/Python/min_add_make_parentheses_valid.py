def minAddToMakeValid(s: str) -> int:
  ans = 0
  stack = []
  for c in s:
    if c == '(':
      stack.append(c)
    elif c == ')' and stack and stack[-1] == '(':
      stack.pop()
    else:
      ans += 1
  return ans + len(stack)

def main():
  s = input()
  print(minAddToMakeValid(s))

if __name__ == '__main__':
  main()