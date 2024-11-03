def main():
  s, goal = [x for x in input().split()]
  print(rotateString(s, goal))

def rotateString(s: str, goal: str) -> bool:
  if len(s) != len(goal):
    return False
  if len(s) == 0:
    return True
  for i in range(len(s)):
    if s[i:] + s[:i] == goal:
      return True
  return False

if __name__ == '__main__':
  main()