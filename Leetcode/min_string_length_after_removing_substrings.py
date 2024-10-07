def minLength(s):
  stack = []
  for c in s:
    if not stack:
      stack.append(c)
      continue
    if c == "B" and stack[-1] == "A":
      stack.pop()
    elif c == "D" and stack[-1] == "C":
      stack.pop()
    else:
      stack.append(c)
  return len(stack)

def main():
  s = input()
  print(minLength(s))

if __name__ == '__main__':
  main()