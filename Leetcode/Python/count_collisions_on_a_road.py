def main():
  directions = input().strip()
  print(countCollisions(directions))

def countCollisions(directions: str) -> int:
  res = 0
  flag = -1
  
  for d in directions:
    if d == "L":
      if flag >= 0:
        res += flag + 1
        flag = 0
    elif d == "S":
      if flag >= 0:
        res += flag
      flag = 0
    else:
      if flag >= 0:
        flag += 1
      else:
        flag = 1

  return res

if __name__ == '__main__':
  main()