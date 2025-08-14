def main():
  num = input()
  print(largestGoodInteger(num))

def largestGoodInteger(num: str) -> str:
  count = 0
  prev = 'X'
  maxd = ' '
  for c in num:
    if c == prev:
      count += 1
    else:
      count = 1
    if count == 3:
      maxd = max(maxd, c)
    prev = c
  return maxd * 3 if maxd != ' ' else ''

if __name__ == '__main__':
  main()